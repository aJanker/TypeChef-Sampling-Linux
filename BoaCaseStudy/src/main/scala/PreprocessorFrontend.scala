import org.anarres.cpp.Main

import java.util.Properties
import java.io.File
import java.io.FileInputStream

import gnu.getopt.Getopt
import gnu.getopt.LongOpt

object PreprocessorFrontend {
    ////////////////////////////////////////
    // General setup of built-in headers, should become more general and move
    // elsewhere.
    ////////////////////////////////////////
    val predefSettings = new Properties()
    val settings = new Properties(predefSettings)

    def systemRoot = settings.getProperty("systemRoot")
    def systemIncludes = settings.getProperty("systemIncludes")
    def predefMacroDef = settings.getProperty("predefMacros")

    def setSystemRoot(value: String) = settings.setProperty("systemRoot", value)

    var preIncludeDirs: Seq[String] = Nil
    var postIncludeDirs: Seq[String] = Nil

    def initSettings {
        predefSettings.setProperty("systemRoot", File.separator)
        predefSettings.setProperty("systemIncludes", "usr" + File.separator + "include")
        predefSettings.setProperty("predefMacros", "host" + File.separator + "platform.h") //XXX not so nice a default
        //XXX no default for GCC includes - hard to guess (one could invoke GCC with special options to get it, though, but it's better to do that to generate the settings file).
    }

    def loadPropList(key: String) = for (x <- settings.getProperty(key, "").split(",")) yield x.trim

    def loadSettings(configPath: String) = {
            settings.load(new FileInputStream(configPath))
            preIncludeDirs = loadPropList("preIncludes") ++ preIncludeDirs
            println("preIncludes: " + preIncludeDirs)
            println("systemIncludes: " + systemIncludes)
            postIncludeDirs = postIncludeDirs ++ loadPropList("postIncludes")
            println("postIncludes: " + postIncludeDirs)
    }

    def includeFlags = (preIncludeDirs ++ List(systemIncludes) ++ postIncludeDirs).flatMap((path: String) =>
        if (path != null && !("" equals path))
            List("-I", systemRoot + File.separator + path)
        else
            List())


    ////////////////////////////////////////
    // Preprocessor/parser invocation
    ////////////////////////////////////////
    def preprocessFile(inFileName: String, outFileName: String, extraOpt: Seq[String]) {
        Main.main(Array(
                inFileName,
                "-o",
                outFileName,
                "--include",
                predefMacroDef
            ) ++
            extraOpt ++
            includeFlags)
    }
    
    def main(args: Array[String]): Unit = {
        initSettings
        var extraOpt = List("-p", "_")
        val optionsToForward = "pPUD"
        val g = new Getopt("testprog", args, ":r:I:c:o:" + optionsToForward.flatMap(x => Seq(x, ':')))
        var loopFlag = true
        var outputFileName: Option[String] = None
        do {
            val c = g.getopt()
            if (c != -1) {
                val arg = g.getOptarg()
                c match {
                    case 'r' => setSystemRoot(arg)
                    case 'I' => postIncludeDirs :+= arg
                    case 'c' => loadSettings(arg)
                    case 'o' => outputFileName = Some(arg)
                    
                    case ':' => println("Missing required argument!"); exit(1)
                    case '?' => println("Unexpected option!"); exit(1)
                    //Pass-through some other options
                    case _ => if (optionsToForward contains c) {
                        extraOpt ++= List("-" + c.asInstanceOf[Char], arg)
                    }
                }
            } else {
                loopFlag = false
            }
        } while (loopFlag)
        println(includeFlags)
        val remArgs = args.slice(g.getOptind(), args.size)
        
        for (filename <- remArgs) {
            outputFileName match {
                case None => outputFileName = Some(filename.replace(".c", "") + ".pi")
                case Some(_) => None
            }
            preprocessFile(filename, outputFileName.get, extraOpt)
        }
    }
}