#ifndef GPIO_PRV_H_
#define GPIO_PRV_H_
#define NULL                    0x0u
#define GPIO_PERIPHERAL_NUM     8u
#define MODER_MASK              0b11u
#define MODER_PIN_ACCESS        2u
#define PUPDR_MASK              0b11u
#define PUPDR_PIN_ACCESS        2u
#define OTYPER_MASK             0b1u
#define OSPEEDR_MASK            0b11u
#define OSPEEDR_PIN_ACCESS      2u
#define AFR_MASK                0b1111u
#define AFR_PIN_ACCESS          4u
#define AFR_PIN_SHIFTING          8u

#endif
