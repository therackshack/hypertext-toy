#include <stdlib.h>
#include <string.h>

struct kv_pair {
	const char *key;
	const char *value;
};

// IF THIS GETS EDITED, MAKE SURE THE ENTRY IS SORTED
// a lot of these are just in here because i thought it was funny
static const struct kv_pair MIME_TYPES[] = {
	{"123", "application/vnd.lotus-1-2-3"},
	{"3g2", "video/3gpp2"},
	{"3gp", "video/3gpp"},
	{"3gpp", "video/3gpp"},
	{"7z", "application/x-7z-compressed"},
	{"aac", "audio/aac"},
	{"abw", "application/x-abiword"},
	{"ai", "application/postscript"},
	{"arc", "application/x-freearc"},
	{"asc", "application/pgp-signature"},
	{"asf", "video/x-ms-asf"},
	{"asx", "video/x-ms-asf"},
	{"atom", "application/atom+xml"},
	{"avi", "video/msvideo"},
	{"avif", "image/avif"},
	{"azw", "application/vnd.amazon.ebook"},
	{"bin", "application/octet-stream"},
	{"bmp", "image/bmp"},
	{"bz", "application/x-bzip"},
	{"bz2", "application/x-bzip2"},
	{"c", "text/x-c"},
	{"cab", "application/vnd.ms-cab-compressed"},
	{"cco", "application/x-cocoa"},
	{"cda", "application/x-cdf"},
	{"chm", "application/vnd.ms-htmlhelp"},
	{"crd", "application/x-mscardfile"},
	{"crt", "application/x-x509-ca-cert"},
	{"csh", "application/x-csh"},
	{"css", "text/css"},
	{"csv", "text/csv"},
	{"deb", "application/x-debian-package"},
	{"der", "application/x-x509-ca-cert"},
	{"dll", "application/octet-stream"},
	{"dmg", "application/x-apple-diskimage"},
	{"doc", "application/msword"},
	{"docm", "application/vnd.ms-word.document.macroenabled.12"},
	{"docx", "application/vnd.openxmlformats-officedocument.wordprocessingml.document"},
	{"dotm", "application/vnd.ms-word.template.macroenabled.12"},
	{"dotx", "application/vnd.openxmlformats-officedocument.wordprocessingml.template"},
	{"dts", "audio/vnd.dts"},
	{"dtshd", "audio/vnd.dts.hd"},
	{"ear", "application/java-archive"},
	{"eot", "application/vnd.ms-fontobject"},
	{"eps", "application/postscript"},
	{"epub", "application/epub+zip"},
	{"exe", "application/x-msdownload"},
	{"flv", "video/x-flv"},
	{"gif", "image/gif"},
	{"gz", "application/gzip"},
	{"hlp", "application/winhlp"},
	{"hpgl", "application/vnd.hp-hpgl"},
	{"hqx", "application/mac-binhex40"},
	{"htc", "text/x-component"},
	{"htm", "text/html"},
	{"html", "text/html"},
	{"ico", "image/x-icon"},
	{"ics", "text/calendar"},
	{"img", "application/octet-stream"},
	{"iso", "application/octet-stream"},
	{"jad", "text/vnd.sun.j2me.app-descriptor"},
	{"jar", "application/java-archive"},
	{"jardiff", "application/x-java-archive-diff"},
	{"jng", "image/x-jng"},
	{"jnlp", "application/x-java-jnlp-file"},
	{"jpeg", "image/jpeg"},
	{"jpg", "image/jpeg"},
	{"js", "application/javascript"},
	{"json", "application/json"},
	{"jsonld", "application/ld+json"},
	{"kar", "audio/midi"},
	{"kml", "application/vnd.google-earth.kml+xml"},
	{"kmz", "application/vnd.google-earth.kmz"},
	{"latex", "application/x-latex"},
	{"m3u", "audio/x-mpegurl"},
	{"m3u8", "application/vnd.apple.mpegurl"},
	{"m4a", "audio/x-m4a"},
	{"m4v", "video/x-m4v"},
	{"mdb", "application/x-msaccess"},
	{"mid", "audio/midi"},
	{"midi", "audio/midi"},
	{"mjs", "application/javascript"},
	{"mml", "text/mathml"},
	{"mng", "video/x-mng"},
	{"mny", "application/x-msmoney"},
	{"mov", "video/quicktime"},
	{"mp3", "audio/mpeg"},
	{"mp4", "video/mp4"},
	{"mpeg", "video/mpeg"},
	{"mpg", "video/mpeg"},
	{"msi", "application/octet-stream"},
	{"msm", "application/octet-stream"},
	{"msp", "application/octet-stream"},
	{"mvb", "application/x-msmediaview"},
	{"obd", "application/x-ms-binder"},
	{"odc", "application/vnd.oasis.opendocument.chart"},
	{"odf", "application/vnd.oasis.opendocument.formula"},
	{"odft", "application/vnd.oasis.opendocument.formula-template"},
	{"odg", "application/vnd.oasis.opendocument.graphics"},
	{"odi", "application/vnd.oasis.opendocument.image"},
	{"odm", "application/vnd.oasis.opendocument.text-master"},
	{"odp", "application/vnd.oasis.opendocument.presentation"},
	{"ods", "application/vnd.oasis.opendocument.spreadsheet"},
	{"odt", "application/vnd.oasis.opendocument.text"},
	{"oga", "audio/ogg"},
	{"ogg", "audio/ogg"},
	{"ogv", "video/ogg"},
	{"ogx", "application/ogg"},
	{"onetoc", "application/onenote"},
	{"opus", "audio/opus"},
	{"otc", "application/vnd.oasis.opendocument.chart-template"},
	{"otf", "font/otf"},
	{"otg", "application/vnd.oasis.opendocument.graphics-template"},
	{"oti", "application/vnd.oasis.opendocument.image-template"},
	{"otp", "application/vnd.oasis.opendocument.presentation-template"},
	{"ots", "application/vnd.oasis.opendocument.spreadsheet-template"},
	{"ott", "application/vnd.oasis.opendocument.text-template"},
	{"pbm", "image/x-portable-bitmap"},
	{"pcl", "application/vnd.hp-pcl"},
	{"pcx", "image/x-pcx"},
	{"pdb", "application/x-pilot"},
	{"pdf", "application/pdf"},
	{"pem", "application/x-x509-ca-cert"},
	{"pfa", "application/x-font-type1"},
	{"pgm", "image/x-portable-graymap"},
	{"pgp", "application/pgp-encrypted"},
	{"php", "application/x-httpd-php"},
	{"pic", "application/x-pict"},
	{"pl", "application/x-perl"},
	{"pm", "application/x-perl"},
	{"png", "image/png"},
	{"pnm", "image/x-portable-anymap"},
	{"potx", "application/vnd.openxmlformats-officedocument.presentationml.template"},
	{"ppm", "image/x-portable-pixmap"},
	{"ppsx", "application/vnd.openxmlformats-officedocument.presentationml.slideshow"},
	{"ppt", "application/vnd.ms-powerpoint"},
	{"pptx", "application/vnd.openxmlformats-officedocument.presentationml.presentation"},
	{"prc", "application/x-pilot"},
	{"ps", "application/postscript"},
	{"pub", "application/x-mspublisher"},
	{"ra", "audio/x-realaudio"},
	{"ram", "audio/x-pn-realaudio"},
	{"rar", "application/x-rar-compressed"},
	{"rm", "application/vnd.rn-realmedia"},
	{"rmp", "audio/x-pn-realaudio-plugin"},
	{"rpm", "application/x-redhat-package-manager"},
	{"rss", "application/rss+xml"},
	{"rtf", "application/rtf"},
	{"run", "application/x-makeself"},
	{"s", "text/x-asm"},
	{"sea", "application/x-sea"},
	{"sh", "application/x-sh"},
	{"shtml", "text/html"},
	{"sig", "application/pgp-signature"},
	{"sit", "application/x-stuffit"},
	{"sitx", "application/x-stuffitx"},
	{"sldx", "application/vnd.openxmlformats-officedocument.presentationml.slide"},
	{"svg", "image/svg+xml"},
	{"svgz", "image/svg+xml"},
	{"swf", "application/x-shockwave-flash"},
	{"tar", "application/x-tar"},
	{"tcl", "application/x-tcl"},
	{"tex", "application/x-tex"},
	{"tfm", "application/x-tex-tfm"},
	{"tif", "image/tiff"},
	{"tiff", "image/tiff"},
	{"tk", "application/x-tcl"},
	{"trm", "application/x-msterminal"},
	{"ts", "video/mp2t"},
	{"ttf", "font/ttf"},
	{"txt", "text/plain"},
	{"vsd", "application/vnd.visio"},
	{"vsdx", "application/vnd.visio2013"},
	{"wad", "application/x-doom"},
	{"war", "application/java-archive"},
	{"wasm", "application/wasm"},
	{"wav", "audio/wav"},
	{"wax", "audio/x-ms-wax"},
	{"wbmp", "image/vnd.wap.wbmp"},
	{"weba", "audio/webm"},
	{"webm", "video/webm"},
	{"webp", "image/webp"},
	{"wm", "video/x-ms-wm"},
	{"wma", "audio/x-ms-wma"},
	{"wmd", "application/x-ms-wmd"},
	{"wmf", "application/x-msmetafile"},
	{"wml", "text/vnd.wap.wml"},
	{"wmlc", "application/vnd.wap.wmlc"},
	{"wmv", "video/x-ms-wmv"},
	{"wmv", "video/x-ms-wmv"},
	{"wmx", "video/x-ms-wmx"},
	{"wmz", "application/x-ms-wmz"},
	{"woff", "font/woff"},
	{"woff2", "font/woff2"},
	{"wpl", "vnd.ms-wpl"},
	{"wps", "application/x-msworks"},
	{"wri", "application/x-mswrite"},
	{"wvx", "video/x-ms-wvx"},
	{"xap", "application/x-silverlight-app"},
	{"xbap", "application/x-ms-xbap"},
	{"xhtml", "application/xhtml+xml"},
	{"xlam", "application/vnd.ms-excel.addin.macroenabled.12"},
	{"xlp", "application/x-msclip"},
	{"xls", "application/vnd.ms-excel"},
	{"xlsb", "application/vnd.ms-excel.sheet.binary.macroenabled.12"},
	{"xlsm", "application/vnd.ms-excel.sheet.macroenabled.12"},
	{"xlsx", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"},
	{"xltm", "application/vnd.ms-excel.template.macroenabled.12"},
	{"xltx", "application/vnd.openxmlformats-officedocument.spreadsheetml.template"},
	{"xml", "application/xml"},
	{"xpi", "application/x-xpinstall"},
	{"xps", "application/vnd.ms-xpsdocument"},
	{"xspf", "application/xspf+xml"},
	{"xul", "application/vnd.mozilla.xul+xml"},
	{"yaml", "text/yaml"},
	{"zip", "application/zip"}
};

static int kvcmp(const void *kv1, const void *kv2) {
    return strcmp(((struct kv_pair *) kv1)->key, ((struct kv_pair *) kv2)->key);
}

// Returns the extension of a file (if there is one)
const char *get_file_ext(const char *path) {
	size_t len = strlen(path);
	const char *ext = path + len;
	while (ext != path && *ext != '.') --ext;
	return ext++ != path ? ext : NULL;
}

// Looks up the mime type associated with a file extension
// Returns the mime type on success, or NULL if it is unknown.
const char *lookup_mime_type(const char *ext) {
	struct kv_pair k = {.key = ext};
	const struct kv_pair *r = bsearch(
		&k, MIME_TYPES, sizeof(MIME_TYPES) / sizeof(MIME_TYPES[0]),
		sizeof(MIME_TYPES[0]), &kvcmp
	);

	return r ? r->value : NULL;
}