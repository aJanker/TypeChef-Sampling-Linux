package de.fosd.typechef.typesystem


class ErrorMsg(msg:String,caller:AST,target:List[Entry]) {
      override def  toString = msg+" ("+caller+" => "+target.mkString(" || ")
}