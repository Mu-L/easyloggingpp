 //
 // This file is part of Easylogging++ samples
 // Custom format specifier
 //
 // Revision 1.0
 // @author mkhan3189
 //

#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

class HttpRequest {
public:
    const char* getIp(void) {
        return "192.168.1.1";
    }
};

int main(void) {
    HttpRequest request;
    // Install format specifier
    el::Helpers::installCustomFormatSpecifier(el::CustomFormatSpecifier("%ip_addr",  std::bind(&HttpRequest::getIp, request)));
    // Either you can do what's done above (for member function) or if you have static function you can simply say
    // el::CustomFormatSpecifier("%ip_addr", getIp)

    // Configure loggers
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format, "%datetime %level %ip_addr : %log");
    LOG(INFO) << "This is after installed 'ip_addr' spec";
    // Uninstall custom format specifier
    el::Helpers::uninstallCustomFormatSpecifier("%ip_addr");
    LOG(INFO) << "This is after uninstalled";
    return 0;
}