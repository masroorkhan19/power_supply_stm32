/*
 * ugui_ST7735.c
 *
 *  Created on: 26.12.2018
 *      Author: Harebit
 */



#include "ugui_ST7789.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

#include "ugui.h"

#define HDP (DISPLAY_WIDTH - 1)
#define VDP (DISPLAY_HEIGHT - 1)
 UG_GUI guiST7735;
 uint8_t ivert_eightbit;
uint32_t send_data;
 struct {
	 uint8_t rdata[4];


 }reg_data;


// union     {
//         uint32_t v32;
//         uint8_t v8[4];
//     }x ={.v8[0] = 0xff, .v8[1] = 0xff, .v8[2] = 0xff, .v8[3] = 0xff};

union   {
             uint16_t v32;
             uint8_t v8[4];
         } y ={.v8[0] = 0xff, .v8[1] = 0xff, .v8[2] = 0x00, .v8[3] = 0x00};

union   {
              uint16_t v32;
              uint8_t v8[4];
         } lower ={.v8[0] = 0x00, .v8[1] = 0x00, .v8[2] = 0x00, .v8[3] = 0x00};

union   {
               uint16_t v32;
               uint8_t v8[4];
         } upper ={.v8[0] = 0x00, .v8[1] = 0x00, .v8[2] = 0x00, .v8[3] = 0x00};
 //ut    y ={.v8[0] = 0xff, .v8[1] = 0xff, .v8[2] = 0x00, .v8[3] = 0x00};

void parallelWriteDC0(uint8_t eightbit){

GPIOA->BSRR |= 0x08000000;
 ivert_eightbit = ~(eightbit);
GPIOB->BSRR = (uint32_t)ivert_eightbit << 24u;
GPIOB->BSRR =(uint32_t)eightbit << 8u;
GPIOA->BSRR |= 0x01000000;
GPIOA->BSRR |= 0x00000100;
}
void opt_delay(uint16_t i)
{
	while(i--);
}
void parallelWriteDC1(uint8_t eightbit){

GPIOA->BSRR |= 0x00000800;
y.v8[1]=eightbit;
GPIOB->ODR &=0x000000ff;
GPIOB->ODR |=(y.v32);
GPIOA->BSRR |= 0x01000000;
GPIOA->BSRR |= 0x00000100;
}







void parallelMultiWriteDC1(uint8_t *p_eightbit, int numItems) {

	for (int i = 0; i < numItems; i++)
	parallelWriteDC1(p_eightbit[i]);

}

 void Display_WriteCommand(uint8_t command)
{
    parallelWriteDC0(command);
}

 void Display_WriteData(uint8_t data)
{
    parallelWriteDC1(data);
}

 void Display_WriteMultiData(uint8_t *data, uint16_t size)
{
//	printf ("data: %X, %X, %X, %X\n",data[0],data[1],data[2],data[3]);
   parallelMultiWriteDC1(data, size);



}

 void Display_Reset()
{
    parallelWriteDC0(0x01);         //Software reset
    HAL_Delay(10);
}

void Display_Init()
{
//	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
//	HAL_Delay(5);
//	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
//	HAL_Delay(15);
//	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RD_GPIO_Port, LCD_RD_Pin, GPIO_PIN_SET);


    parallelWriteDC0(0x01);   //Software Reset
    HAL_Delay(100);

    //--------------display and color format setting ----------//
    parallelWriteDC0(0x11);
    HAL_Delay(100);
    parallelWriteDC0(0x36);
    parallelWriteDC1(0x60);  // rotate 90
    parallelWriteDC0(0x3a);
    parallelWriteDC1(0x05);
    //---------------------st7789 frame rate
    parallelWriteDC0(0xb2);
    parallelWriteDC1(0x0c);
    parallelWriteDC1(0x0c);
    parallelWriteDC1(0x00);
    parallelWriteDC1(0x33);
    parallelWriteDC1(0x33);
    parallelWriteDC0(0xb7);
    parallelWriteDC1(0x35);
    //---------------------st7789 power setting
    parallelWriteDC0(0xbb);
    parallelWriteDC1(0x28);
    parallelWriteDC0(0xc0);
    parallelWriteDC1(0x2c);
    parallelWriteDC0(0xc2);
    parallelWriteDC1(0x01);
    parallelWriteDC1(0xFF);
    parallelWriteDC0(0xc3);
    parallelWriteDC1(0x0b);
    parallelWriteDC0(0xc4);
    parallelWriteDC1(0x20);
    parallelWriteDC0(0xc6);
    parallelWriteDC1(0x0f);
    parallelWriteDC0(0xd0);
    parallelWriteDC1(0xa4);
    parallelWriteDC1(0xa1);
    //-------------st7789 gamma setting
    parallelWriteDC0(0xe0);
    parallelWriteDC1(0xd0);
    parallelWriteDC1(0x01);
    parallelWriteDC1(0x08);
    parallelWriteDC1(0x0f);
    parallelWriteDC1(0x11);
    parallelWriteDC1(0x2a);
    parallelWriteDC1(0x36);
    parallelWriteDC1(0x55);
    parallelWriteDC1(0x44);
    parallelWriteDC1(0x3a);
    parallelWriteDC1(0x0b);
    parallelWriteDC1(0x06);
    parallelWriteDC1(0x11);
    parallelWriteDC1(0x20);
    parallelWriteDC1(0xe1);
    parallelWriteDC1(0xd0);
    parallelWriteDC1(0x02);
    parallelWriteDC1(0x07);
    parallelWriteDC1(0x0a);
    parallelWriteDC1(0x0b);
    parallelWriteDC1(0x18);
    parallelWriteDC1(0x34);
    parallelWriteDC1(0x43);
    parallelWriteDC1(0x4a);
    parallelWriteDC1(0x2b);
    parallelWriteDC1(0x1b);
    parallelWriteDC1(0x1c);
    parallelWriteDC1(0x22);
    parallelWriteDC1(0x1f);
    parallelWriteDC0(0x29);
    parallelWriteDC0(0x2c);
    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);

    // Initialize global structure and set PSET to this.PSET.
    UG_Init(&guiST7735, Display_PSet, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    //
    guiST7735.desktop_color= C_BLACK;
    // Register accelerators.
    UG_DriverRegister(DRIVER_FILL_FRAME, (void*)HW_FillFrame);
    UG_DriverRegister(DRIVER_DRAW_LINE, (void*)HW_DrawLine);
    UG_DriverRegister(DRIVER_DRAW_IMAGE, (void*)HW_DrawImage);
}

void Display_WindowSet(unsigned int s_x,unsigned int e_x,unsigned int s_y,unsigned int e_y)
{
    uint8_t data[4];

    data[0] = ((s_x)>>8);                   //SET start column address
    data[1] = (s_x);
    data[2] = ((e_x)>>8);			        //SET end column address
    data[3] = (e_x);
	Display_WriteCommand(0x2a);		        //SET column address
//	printf ("data: %X, %X, %X, %X\n",data[0],data[1],data[2],data[3]);
    Display_WriteMultiData(data, 4);


    data[0] = ((s_y)>>8);                   //SET start row address
    data[1] = (s_y);
    data[2] = ((e_y)>>8);			        //SET end row address
    data[3] = (e_y);
	Display_WriteCommand(0x2b);		        //SET row address
    Display_WriteMultiData(data, 4);
}

void Display_PSet(UG_S16 x, UG_S16 y, UG_COLOR c)
{
    if((x < 0) ||(x >= DISPLAY_WIDTH) || (y < 0) || (y >= DISPLAY_HEIGHT)) return;

    Display_WindowSet(x, x + 1, y, y + 1);
    Display_WriteCommand(0x2c);

#ifdef USE_COLOR_RGB888 // 24-bit colour 8*Red-8*Green-8*Blue

        	uint8_t data[3];

            data[0] = (c >> 16);
            data[1] = (c >> 8);
            data[2] = (c);

            Display_WriteMultiData(data, 3);
#endif
#ifdef USE_COLOR_RGB565 // 16-bit colour 5*Red-6*Green-5*Blue

        	uint8_t data[2];

            data[0] = (c >> 8);
            data[1] = (c);

            Display_WriteMultiData(data, 2);

#endif


}

UG_RESULT HW_FillFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c)
{
   // uint16_t loopx, loopy;


    if((x1 < 0) ||(x1 >= DISPLAY_WIDTH) || (y1 < 0) || (y1 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;
    if((x2 < 0) ||(x2 >= DISPLAY_WIDTH) || (y2 < 0) || (y2 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;
    Display_WindowSet(x1,x2,y1,y2);
    Display_WriteCommand(0x2c);
    uint32_t  do_loop = (x1-(x2+1))*(y1-(y2+1));

    //#ifdef USE_COLOR_RGB565 // 16-bit colour 5*Red-6*Green-5*Blue
       lower.v8[1]= (c >> 8);
       lower.v8[3] = ~(lower.v8[1]);
       upper.v8[1]= (c);
       upper.v8[3]= ~(upper.v8[1]);
	//#endif

       GPIOA->BSRR |= 0x00000800;
       do{
    //	GPIOB->ODR &=0x000000ff;
    //	GPIOB->ODR |=(y.v32);
    	   GPIOB->BSRR = lower.v8[3]<<24;
    	   GPIOB->BSRR = lower.v8[1]<<8;
    	GPIOA->BSRR |= 0x01000000;
    	GPIOA->BSRR |= 0x00000100;
//    	GPIOB->ODR &=0x000000ff;
//    	GPIOB->ODR |=(x.v32);
    	GPIOB->BSRR = upper.v8[3]<<24;
    	GPIOB->BSRR = upper.v8[1]<<8;
        GPIOA->BSRR |= 0x01000000;
        GPIOA->BSRR |= 0x00000100;
       }while(--(do_loop)!=0);

    return UG_RESULT_OK;
}

UG_RESULT HW_DrawLine( UG_S16 x1 , UG_S16 y1 , UG_S16 x2 , UG_S16 y2 , UG_COLOR c )
{
    if((x1 < 0) ||(x1 >= DISPLAY_WIDTH) || (y1 < 0) || (y1 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;
    if((x2 < 0) ||(x2 >= DISPLAY_WIDTH) || (y2 < 0) || (y2 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;

    // If it is a vertical or a horizontal line, draw it.
    // If not, then use original drawline routine.
    if ((x1 == x2) || (y1 == y2))
    {
        HW_FillFrame(x1, y1, x2, y2, c);
        return UG_RESULT_OK;
    }

    return UG_RESULT_FAIL;
}

UG_RESULT HW_DrawImage(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, uint16_t *image, uint16_t pSize)
{

    if((x1 < 0) ||(x1 >= DISPLAY_WIDTH) || (y1 < 0) || (y1 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;
    if((x2 < 0) ||(x2 >= DISPLAY_WIDTH) || (y2 < 0) || (y2 >= DISPLAY_HEIGHT)) return UG_RESULT_FAIL;

    Display_WindowSet(x1,x2,y1,y2);

#ifdef USE_COLOR_RGB888 // 24-bit colour 8*Red-8*Green-8*Blue

    Display_WriteCommand(0x2c);
    Display_WriteMultiData(image, pSize*3);

#endif
#ifdef USE_COLOR_RGB565 // 16-bit colour 5*Red-6*Green-5*Blue

    Display_WriteCommand(0x2c);

    uint16_t i;
    uint16_t buffer[(pSize-1)];
    uint16_t *ptr = image;
    uint8_t data[2];

    for(i=0 ;i < pSize; i++)
    {
    	buffer[i] = *(ptr++);

            data[0] = (buffer[i] >> 8);
            data[1] = (buffer[i]);
 //           printf("data: %X, %X\n",data[0],data[1]);
            Display_WriteMultiData(data, 2);
    }
#endif
    return UG_RESULT_OK;
}

/* [] END OF FILE */
