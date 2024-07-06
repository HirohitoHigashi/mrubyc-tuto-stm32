sleep 1    # task1で、$cycle_delay へ代入される事を確実にするため

while true
  gpio_pa10_write( 1 )
  sleep $cycle_delay
  gpio_pa10_write( 0 )
  sleep $cycle_delay
end
