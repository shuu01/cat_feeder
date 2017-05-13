# cat_feeder
cat feeder based on arduino with 28byj-48 step motor and ds1307 clock module

build: ```ino build```
upload via usbasp: avrdude -c usbasp -p m328p -P usb -U flash:w:.build/mini328/firmware.hex
