/* Generated by GOB (v2.0.15)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef __GNOME_PILOT_CONDUIT_H__
#define __GNOME_PILOT_CONDUIT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gnome.h>
#include "gnome-pilot-dbinfo.h"
#include "gnome-pilot-structures.h"


/*
 * Type checking and casting macros
 */
#define GNOME_TYPE_PILOT_CONDUIT	(gnome_pilot_conduit_get_type())
#define GNOME_PILOT_CONDUIT(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), gnome_pilot_conduit_get_type(), GnomePilotConduit)
#define GNOME_PILOT_CONDUIT_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), gnome_pilot_conduit_get_type(), GnomePilotConduit const)
#define GNOME_PILOT_CONDUIT_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), gnome_pilot_conduit_get_type(), GnomePilotConduitClass)
#define GNOME_IS_PILOT_CONDUIT(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), gnome_pilot_conduit_get_type ())

#define GNOME_PILOT_CONDUIT_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), gnome_pilot_conduit_get_type(), GnomePilotConduitClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_GNOME_PILOT_CONDUIT__
#define __TYPEDEF_GNOME_PILOT_CONDUIT__
typedef struct _GnomePilotConduit GnomePilotConduit;
#endif
struct _GnomePilotConduit {
	GtkObject __parent__;
	/*< public >*/
	gchar * name;
	gint progress_stepping;
	gint progress_top;
	/*< private >*/
	GPilotPilot * pilot; /* protected */
};

/*
 * Class definition
 */
typedef struct _GnomePilotConduitClass GnomePilotConduitClass;
struct _GnomePilotConduitClass {
	GtkObjectClass __parent__;
	/*signal*/void (* progress) (GnomePilotConduit * self, gint total, gint current);
	/*signal*/void (* message) (GnomePilotConduit * self, gchar * message);
	/*signal*/void (* warning) (GnomePilotConduit * self, gchar * message);
	/*signal*/void (* error) (GnomePilotConduit * self, gchar * message);
	/*signal*/int (* create_settings_window) (GnomePilotConduit * self, GtkWidget * parent);
	/*signal*/void (* display_settings) (GnomePilotConduit * self);
	/*signal*/void (* save_settings) (GnomePilotConduit * self);
	/*signal*/void (* revert_settings) (GnomePilotConduit * self);
};


/*
 * Public methods
 */
GType	gnome_pilot_conduit_get_type	(void);
gchar * 	gnome_pilot_conduit_get_name	(GnomePilotConduit * self);
void 	gnome_pilot_conduit_set_name	(GnomePilotConduit * self,
					gchar * val);
GtkObject * 	gnome_pilot_conduit_new	(void);
void 	gnome_pilot_conduit_progress	(GnomePilotConduit * self,
					gint total,
					gint current);
void 	gnome_pilot_conduit_send_progress	(GnomePilotConduit * self,
					gint total,
					gint current);
void 	gnome_pilot_conduit_message	(GnomePilotConduit * self,
					gchar * message);
void 	gnome_pilot_conduit_warning	(GnomePilotConduit * self,
					gchar * message);
void 	gnome_pilot_conduit_error	(GnomePilotConduit * self,
					gchar * message);
void 	gnome_pilot_conduit_send_message	(GnomePilotConduit * self,
					gchar * message,
					...);
void 	gnome_pilot_conduit_send_warning	(GnomePilotConduit * self,
					gchar * message,
					...);
void 	gnome_pilot_conduit_send_error	(GnomePilotConduit * self,
					gchar * message,
					...);
int 	gnome_pilot_conduit_create_settings_window	(GnomePilotConduit * self,
					GtkWidget * parent);
void 	gnome_pilot_conduit_display_settings	(GnomePilotConduit * self);
void 	gnome_pilot_conduit_save_settings	(GnomePilotConduit * self);
void 	gnome_pilot_conduit_revert_settings	(GnomePilotConduit * self);
const gchar * 	gnome_pilot_conduit_get_base_dir	(GnomePilotConduit * self);

/*
 * Signal connection wrapper macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define gnome_pilot_conduit_connect__progress(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"progress",(GCallback) __extension__ ({void (* ___progress) (GnomePilotConduit * ___fake___self, gint ___fake___total, gint ___fake___current, gpointer ___data ) = (func); ___progress; }), (data))
#define gnome_pilot_conduit_connect_after__progress(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"progress",(GCallback) __extension__ ({void (* ___progress) (GnomePilotConduit * ___fake___self, gint ___fake___total, gint ___fake___current, gpointer ___data ) = (func); ___progress; }), (data))
#define gnome_pilot_conduit_connect_data__progress(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"progress",(GCallback) __extension__ ({void (* ___progress) (GnomePilotConduit * ___fake___self, gint ___fake___total, gint ___fake___current, gpointer ___data ) = (func); ___progress; }), (data), (destroy_data), (GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__message(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"message",(GCallback) __extension__ ({void (* ___message) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___message; }), (data))
#define gnome_pilot_conduit_connect_after__message(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"message",(GCallback) __extension__ ({void (* ___message) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___message; }), (data))
#define gnome_pilot_conduit_connect_data__message(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"message",(GCallback) __extension__ ({void (* ___message) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___message; }), (data), (destroy_data), (GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__warning(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"warning",(GCallback) __extension__ ({void (* ___warning) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___warning; }), (data))
#define gnome_pilot_conduit_connect_after__warning(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"warning",(GCallback) __extension__ ({void (* ___warning) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___warning; }), (data))
#define gnome_pilot_conduit_connect_data__warning(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"warning",(GCallback) __extension__ ({void (* ___warning) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___warning; }), (data), (destroy_data), (GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__error(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"error",(GCallback) __extension__ ({void (* ___error) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___error; }), (data))
#define gnome_pilot_conduit_connect_after__error(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"error",(GCallback) __extension__ ({void (* ___error) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___error; }), (data))
#define gnome_pilot_conduit_connect_data__error(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"error",(GCallback) __extension__ ({void (* ___error) (GnomePilotConduit * ___fake___self, gchar * ___fake___message, gpointer ___data ) = (func); ___error; }), (data), (destroy_data), (GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__create_settings_window(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"create_settings_window",(GCallback) __extension__ ({int (* ___create_settings_window) (GnomePilotConduit * ___fake___self, GtkWidget * ___fake___parent, gpointer ___data ) = (func); ___create_settings_window; }), (data))
#define gnome_pilot_conduit_connect_after__create_settings_window(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"create_settings_window",(GCallback) __extension__ ({int (* ___create_settings_window) (GnomePilotConduit * ___fake___self, GtkWidget * ___fake___parent, gpointer ___data ) = (func); ___create_settings_window; }), (data))
#define gnome_pilot_conduit_connect_data__create_settings_window(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"create_settings_window",(GCallback) __extension__ ({int (* ___create_settings_window) (GnomePilotConduit * ___fake___self, GtkWidget * ___fake___parent, gpointer ___data ) = (func); ___create_settings_window; }), (data), (destroy_data), (GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__display_settings(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"display_settings",(GCallback) __extension__ ({void (* ___display_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___display_settings; }), (data))
#define gnome_pilot_conduit_connect_after__display_settings(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"display_settings",(GCallback) __extension__ ({void (* ___display_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___display_settings; }), (data))
#define gnome_pilot_conduit_connect_data__display_settings(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"display_settings",(GCallback) __extension__ ({void (* ___display_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___display_settings; }), (data), (destroy_data), (GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__save_settings(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"save_settings",(GCallback) __extension__ ({void (* ___save_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___save_settings; }), (data))
#define gnome_pilot_conduit_connect_after__save_settings(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"save_settings",(GCallback) __extension__ ({void (* ___save_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___save_settings; }), (data))
#define gnome_pilot_conduit_connect_data__save_settings(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"save_settings",(GCallback) __extension__ ({void (* ___save_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___save_settings; }), (data), (destroy_data), (GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__revert_settings(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"revert_settings",(GCallback) __extension__ ({void (* ___revert_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___revert_settings; }), (data))
#define gnome_pilot_conduit_connect_after__revert_settings(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"revert_settings",(GCallback) __extension__ ({void (* ___revert_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___revert_settings; }), (data))
#define gnome_pilot_conduit_connect_data__revert_settings(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(__extension__ ({GnomePilotConduit *___object = (object); ___object; })),"revert_settings",(GCallback) __extension__ ({void (* ___revert_settings) (GnomePilotConduit * ___fake___self, gpointer ___data ) = (func); ___revert_settings; }), (data), (destroy_data), (GConnectFlags)(flags))
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define gnome_pilot_conduit_connect__progress(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(object),"progress",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_after__progress(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(object),"progress",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_data__progress(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(object),"progress",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__message(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(object),"message",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_after__message(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(object),"message",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_data__message(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(object),"message",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__warning(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(object),"warning",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_after__warning(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(object),"warning",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_data__warning(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(object),"warning",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__error(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(object),"error",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_after__error(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(object),"error",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_data__error(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(object),"error",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__create_settings_window(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(object),"create_settings_window",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_after__create_settings_window(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(object),"create_settings_window",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_data__create_settings_window(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(object),"create_settings_window",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__display_settings(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(object),"display_settings",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_after__display_settings(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(object),"display_settings",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_data__display_settings(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(object),"display_settings",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__save_settings(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(object),"save_settings",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_after__save_settings(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(object),"save_settings",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_data__save_settings(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(object),"save_settings",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#define gnome_pilot_conduit_connect__revert_settings(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT(object),"revert_settings",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_after__revert_settings(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT(object),"revert_settings",(GCallback)(func),(data))
#define gnome_pilot_conduit_connect_data__revert_settings(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT(object),"revert_settings",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#endif /* __GNUC__ && !__STRICT_ANSI__ */


/*
 * Argument wrapping macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define GNOME_PILOT_CONDUIT_PROP_NAME(arg)    	"name", __extension__ ({gchar * z = (arg); z;})
#define GNOME_PILOT_CONDUIT_GET_PROP_NAME(arg)	"name", __extension__ ({gchar * *z = (arg); z;})
#define GNOME_PILOT_CONDUIT_PROP_PROGRESS_STEPPING(arg)    	"progress_stepping", __extension__ ({gint z = (arg); z;})
#define GNOME_PILOT_CONDUIT_GET_PROP_PROGRESS_STEPPING(arg)	"progress_stepping", __extension__ ({gint *z = (arg); z;})
#define GNOME_PILOT_CONDUIT_PROP_PROGRESS_TOP(arg)    	"progress_top", __extension__ ({gint z = (arg); z;})
#define GNOME_PILOT_CONDUIT_GET_PROP_PROGRESS_TOP(arg)	"progress_top", __extension__ ({gint *z = (arg); z;})
#define GNOME_PILOT_CONDUIT_PROP_PILOT(arg)    	"pilot", __extension__ ({GPilotPilot * z = (arg); z;})
#define GNOME_PILOT_CONDUIT_GET_PROP_PILOT(arg)	"pilot", __extension__ ({GPilotPilot * *z = (arg); z;})
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define GNOME_PILOT_CONDUIT_PROP_NAME(arg)    	"name",(gchar * )(arg)
#define GNOME_PILOT_CONDUIT_GET_PROP_NAME(arg)	"name",(gchar * *)(arg)
#define GNOME_PILOT_CONDUIT_PROP_PROGRESS_STEPPING(arg)    	"progress_stepping",(gint )(arg)
#define GNOME_PILOT_CONDUIT_GET_PROP_PROGRESS_STEPPING(arg)	"progress_stepping",(gint *)(arg)
#define GNOME_PILOT_CONDUIT_PROP_PROGRESS_TOP(arg)    	"progress_top",(gint )(arg)
#define GNOME_PILOT_CONDUIT_GET_PROP_PROGRESS_TOP(arg)	"progress_top",(gint *)(arg)
#define GNOME_PILOT_CONDUIT_PROP_PILOT(arg)    	"pilot",(GPilotPilot * )(arg)
#define GNOME_PILOT_CONDUIT_GET_PROP_PILOT(arg)	"pilot",(GPilotPilot * *)(arg)
#endif /* __GNUC__ && !__STRICT_ANSI__ */



typedef GnomePilotConduit *(*GnomePilotConduitOldLoadFunc)(guint32);
typedef GnomePilotConduit *(*GnomePilotConduitLoadFunc)(GPilotPilot*);
typedef void (*GnomePilotConduitDestroyFunc)(GnomePilotConduit *);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
