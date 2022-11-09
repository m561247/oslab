#include <linux/module.h>

int data = 1, month = 1, year = 2000;

module_param(date, int, 0);
MODULE_PARAM_DESC(date, "Date of time");
module_param(month, int, 0);
MODULE_PARAM_DESC(month, "Month of time");
module_param(year, int, 0);
MODULE_PARAM_DESC(year, "Year of time");

int init_module(void) {
	printk(KERNO_INFO "Insert hello_module successfully.\n");
	printk(KERNO_INFO "Today is %d%d%d\n", year, month, date);
	return 0;
}

void cleanup_module(void) {
	printk(KERNO_INFO "Remove hello_module successfully.\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FE");
MODULE_DESCRIPTION("OSLAB_MODULE: hello_module");

