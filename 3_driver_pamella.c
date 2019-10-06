#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

int driver_caracter_open(struct inode *pinode, struct file *pfile){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    return 0;
}
ssize_t driver_caracter_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offet){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    return 0;
}
ssize_t driver_caracter_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    return length;
}
int driver_caracter_close(struct inode *pinode, struct file *pfile){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    return 0;
}

struct file_operations file_operations_n = {
    .owner = THIS_MODULE,
    .open = driver_caracter_open,
    .read = driver_caracter_read,
    .write = driver_caracter_write,
    .release = driver_caracter_close,
};

int driver_caracter_init(void){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    register_chrdev(185, "Driver Pamella", &file_operations_n);
    return 0;
}
void driver_caracter_exit(void){
    printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
    unregister_chrdev(185, "Driver");
}
module_init(driver_caracter_init);
module_exit(driver_caracter_exit);
