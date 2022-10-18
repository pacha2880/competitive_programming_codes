#include <conio.h>  //De aquí utilizaremos la función kbhit() 
#include <stdlib.h> //De aquí sacaremos la función random()
#include <dos.h> //Usaremos esta librería por la función delay(int valor) que nos permite            
                 //establecer un retardo en milisegundos.
#include <graphics.h> //Esta es la librería que nos permite usar gráficos.

void main()
{
 int gdriver=DETECT, gmode, contador=0;
 initgraph(&gdriver,&gmode,"C:\\BORLANDC\\BGI");  //Iniciamos el modo gráfico.
 do
   {
    setcolor(random(15));   //Establecemos un color aleatorio
    line(random(640),random(480),random(640),random(480)); //Establecemos coordenadas aleatorias.
    setcolor(random(15));
    rectangle(random(640),random(480),random(640),random(480));
    setcolor(random(15));
    ellipse(random(640),random(480),0,360,random(100),random(100));
    contador+=1;   //Por cada vuelta incrementamos contador en 1.
    if(contador%100==0) { cleardevice(); }   //Si contador es múltiplo de 100, limpia la pantalla.
    delay(100);    //Establecemos un retardo de 100 milisegundos al dibujar las figuras. 
   }
 while(!kbhit());  //Si se pulsa alguna tecla, salimos del programa.
 closegraph();     //Cerramos el modo gráfico.
}