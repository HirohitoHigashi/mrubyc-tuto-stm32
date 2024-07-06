#include "main.h"
#include "../mrubyc_src/mrubyc.h"

static void c_led_write(mrbc_vm *vm, mrbc_value v[], int argc);

/* mruby/c プログラムが使うワークメモリの確保 */
#define MRBC_MEMORY_SIZE (1024*30)
static uint8_t memory_pool[MRBC_MEMORY_SIZE];

/*! mruby/c プログラムの実行開始
*/
void start_mrubyc( void )
{
  mrbc_init(memory_pool, MRBC_MEMORY_SIZE);

  // ユーザ定義メソッドの登録
  mrbc_define_method(0, 0, "led_write", c_led_write);

  // タスクの登録
  extern const uint8_t task1[];
  mrbc_create_task( task1, 0 );

  // 実行開始
  mrbc_run();
}


/*! オンボードLED ON/OFF メソッドの実装
*/
static void c_led_write(mrbc_vm *vm, mrbc_value v[], int argc)
{
  int on_off = GET_INT_ARG(1);
  HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, on_off );
}

/*! HAL
*/
int hal_write(int fd, const void *buf, int nbytes)
{
  extern UART_HandleTypeDef huart2;
  HAL_UART_Transmit( &huart2, buf, nbytes, HAL_MAX_DELAY );

  return nbytes;
}

int _write(int file, char *ptr, int len)
{
  return hal_write(file, ptr, len);
}

int hal_flush(int fd)
{
  return 0;
}

void hal_abort(const char *s)
{
}