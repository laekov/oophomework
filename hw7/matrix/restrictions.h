#if __GNUC__ < 6
#	error Failing compilation "Please use gcc whose version >= 6"
#endif

#ifdef WIN32
#	warning "This project is not and will never be promised to run correctly under windows."
#endif
