#    include "sam.h"
#    include "arm_atsam_protocol.h"
#    include "serial_print.h"
#    include <string.h>
#    include <stdarg.h>

void puts_(const char *s);
void serial_printf(char *fmt, ...) {
    while (udi_hid_con_b_report_trans_ongoing) {
    }  // Wait for any previous transfers to complete

    static char serial_printbuf[SERIAL_PRINTBUF_SIZE];  // Print and send buffer
    va_list     va;
    int         result;

    va_start(va, fmt);
    result = vsnprintf(serial_printbuf, SERIAL_PRINTBUF_SIZE, fmt, va);
    va_end(va);
    
    if (result > 0) {
	puts_(serial_printbuf);
    }
}
