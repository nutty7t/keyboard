keymap_dir = qmk_firmware/keyboards/keebio/iris/keymaps/nutty7t
keymap_files = $(addprefix $(keymap_dir)/,keymap.c config.h rules.mk)

qmk_firmware:
	git clone https://github.com/qmk/qmk_firmware

$(keymap_dir): qmk_firmware
	mkdir -p $@

$(keymap_files): $(keymap_dir)
	if [ ! -f $@ ]; then ln -s $(shell pwd)/$(notdir $@) $@; fi;

all: $(keymap_files)
	echo "done"

clean:
	rm -rf qmk_firmware/

.PHONY: clean all
