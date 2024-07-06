$cycle_delay = 1

while true
  sw = sw_read()
  led_write( sw )

  if sw == 1
    $cycle_delay = 0.2
  else
    $cycle_delay = 1
  end
end
