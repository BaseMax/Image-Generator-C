/*
 * Name: Image Generator C
 * Description: A C program to generate bmp image with random color.
 * Author: Max Base
 * Date: 2022-02-11
 * Repository: https://github.com/BaseMax/Image-Generator-C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



                                              typedef                           
                                            struct{int                        
                                            r;int g;int b                       
                                         ;}rgb;rgb   rc(){int                     
                                        m=             255;rgb c                     
                                        ;c.              r=rand()                    
                                       %m;c               .g=rand                   
                                       ()%                  m;c.b=                   
                                       rand()               %m;return                   
                                       c;                    }void                   
                                       ri                    (char                   
                                      *f,                 int w,int                   
                                      h){FILE*fp           =fopen(f,                 
                                       "wb"    );if       (fp==NULL)                  
                                       {printf            ("Error:"                  
                                        /*PROGRAM*/      ": cannot"                  
                                        "open"          " file %s"                   
                                         "\n"          ,f);return                    
                                         /*BASE*/      ;}int p=(4                    
                                          -   (w*3)%4)%4;int                    
                                           sz  =54+(w+p)*h*3                    
                                           ;int    iw=w;int                     
                                            ih=  h;int bpp=3                    
                                            ;int    bp=bpp*iw+                  
                                            p;int  image_size=bp*ih              
                                           ;int    xp=2835;int yp=2835           
                                        ;int u=    0;int i=0;unsigned         
                                      char hs[62      ]={'B','M',sz,sz>>8,sz    
                                   >>16,sz>>24,0     ,0,0,0,54,0,0,0,40,0,0,0,iw
                                 ,iw>>8,iw>>16,   iw>>24,ih,ih>>8,ih>>16,ih>>24,
                              1,0,24,0,0,0,0,0    ,0,0,0,0,0,0,0,0,xp,xp>>8,xp>>
                            16,xp>>24,yp,yp>>    8,yp>>16,yp>>24,0,0,0,0,u,u>>8,u
                           >>16,u>>24,i,i>>8,i       >>16,i>>24};fwrite(hs,sizeof
                         (unsigned char),54,fp);rgb c;int k=0;for(int i=0;i<h;i++){
                        for(int j=0;j<w;j++){if(k==0)c=rc();else if(rand()%4>2)c=rc
                        ();fwrite(&c.b,sizeof(   unsigned char),1,fp);fwrite(&c.g,
                       sizeof(unsigned char),1,fp);   fwrite(&c.r,sizeof(unsigned
                       char),1,fp);k++;}for(int k=0;  k<p;k++){fwrite(&c.b,sizeof(
                      unsigned char),1,fp);}}fclose(fp);printf("Success: create i"
                      "mage %s\n",f);}int main(){ri("test.bmp",256,256);return 0;}


