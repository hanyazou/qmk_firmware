# Hey Emacs, this is a -*- makefile -*-
##############################################################################
# Compiler settings
#
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size
AR = arm-none-eabi-ar
NM = arm-none-eabi-nm
HEX = $(OBJCOPY) -O $(FORMAT) -R .eeprom -R .fuse -R .lock -R .signature
EEP = $(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O $(FORMAT)
BIN =

ifeq ($(ARM_ATSAM_ASF), __SAMD21E17A__)
MCU = cortex-m0plus
HAVE_FPU = no
SAMD = samd21
SAMD_I2C = sam0
SAMD_CLOCK = samd21_r21_da_ha1
LD_FILE = samd21e17a_flash.ld
else
$(error $(ARM_ATSAM_ASF) is not suppoeted)
endif

SDK = $(LIB_PATH)/arm_atsam_asf/microchip-asf

INCS += $(SDK)/common/utils
INCS += $(SDK)/common2/services
INCS += $(SDK)/common2/services/delay
INCS += $(SDK)/sam0/drivers
INCS += $(SDK)/sam0/drivers/system
INCS += $(SDK)/sam0/drivers/system/clock
INCS += $(SDK)/sam0/drivers/system/clock/clock_$(SAMD_CLOCK)
INCS += $(SDK)/sam0/drivers/sercom
INCS += $(SDK)/sam0/drivers/system/interrupt
INCS += $(SDK)/sam0/drivers/system/interrupt/system_interrupt_$(SAMD)
INCS += $(SDK)/sam0/drivers/system/pinmux
INCS += $(SDK)/sam0/drivers/system/power/power_sam_d_r_h
INCS += $(SDK)/sam0/drivers/system/reset/reset_sam_d_r_h
INCS += $(SDK)/sam0/utils
INCS += $(SDK)/sam0/utils/cmsis/$(SAMD)/include
INCS += $(SDK)/sam0/utils/cmsis/$(SAMD)/source
INCS += $(SDK)/sam0/utils/header_files
INCS += $(SDK)/sam0/utils/preprocessor
INCS += $(SDK)/thirdparty/CMSIS/Include
INCS += app/config

COMPILEFLAGS += -funsigned-char
COMPILEFLAGS += -funsigned-bitfields
COMPILEFLAGS += -ffunction-sections
COMPILEFLAGS += -fshort-enums
COMPILEFLAGS += -fno-inline-small-functions
COMPILEFLAGS += -fno-strict-aliasing
ifeq ($(HAVE_FPU), yes)
COMPILEFLAGS += -mfloat-abi=hard
COMPILEFLAGS += -mfpu=fpv4-sp-d16
endif
COMPILEFLAGS += -mthumb
#COMPILEFLAGS += -DTHUMB
#COMPILEFLAGS += -DTHUMB_PRESENT
#COMPILEFLAGS += -DTHUMB_NO_INTERWORKING
#COMPILEFLAGS += -mno-thumb-interwork

ALLOW_WARNINGS = yes

CFLAGS += $(COMPILEFLAGS) $(addprefix -I, $(INCS))

CXXFLAGS += $(COMPILEFLAGS)
CXXFLAGS += -fno-exceptions -std=c++11

LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,-Map="%OUT%%PROJ_NAME%.map"
LDFLAGS += -Wl,--start-group
LDFLAGS += -Wl,--end-group
LDFLAGS += --specs=rdimon.specs
LDFLAGS += -T$(SDK)/sam0/utils/linker_scripts/$(SAMD)/gcc/$(LD_FILE)

OPT_DEFS += -DPROTOCOL_ARM_ATSAM_ASF

MCUFLAGS = -mcpu=$(MCU)
MCUFLAGS += -D__$(ARM_ATSAM)__ -D$(ARM_ATSAM_ASF)

# List any extra directories to look for libraries here.
#     Each directory must be seperated by a space.
#     Use forward slashes for directory separators.
#     For a directory that has spaces, enclose it in quotes.
EXTRALIBDIRS =

# Convert hex to bin.
bin: $(BUILD_DIR)/$(TARGET).hex
	$(OBJCOPY) -Iihex -Obinary $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin
	$(COPY) $(BUILD_DIR)/$(TARGET).bin $(TARGET).bin;

flash: bin
	$(PRINT_OK); $(SILENT) || printf "$(MSG_FLASH_ARCH)"
