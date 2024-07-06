#ifndef MRBC_SRC_HAL_H_
#define MRBC_SRC_HAL_H_

#define MRBC_TICK_UNIT 1
#define MRBC_TIMESLICE_TICK_COUNT 10

#define hal_init()        ((void)0)
#define hal_enable_irq()  ((void)0)
#define hal_disable_irq() ((void)0)
#define hal_idle_cpu()    (HAL_Delay(MRBC_TICK_UNIT), mrbc_tick())

int hal_write(int fd, const void *buf, int nbytes);
int hal_flush(int fd);
void hal_abort(const char *s);

#endif
