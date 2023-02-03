#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdio.h>
// Estructura WAV
typedef struct {
  char chunkID[4];
  int chunkSize;
  char format[4];
  char subchunk1ID[4];
  int subchunk1Size;
  short int audioFormat;
  short int numChannels;
  int sampleRate;
  int byteRate;
  short int blockAlign;
  short int bitsPerSample;
  char subchunk2ID[4];
  int subchunk2Size;
} WAV;


int main(int argc, char *argv[])
{
  FILE *w;
  WAV archivo;
  uint8_t *data;
  double time_to_advance;
  double *y;
  uint32_t num_samples, bytes_to_advance;
  
  // Abrir archivo WAV 
  w = fopen("ronaldo-siuuuu.wav", "rb");
  
  // Leer archivo WAV
  fread(&archivo, sizeof(WAV), 1, w);

  // Mostrar información del archivo WAV
  printf("Chunk ID: %.*s\n", 4, archivo.chunkID);
  printf("Chunk size: %d\n", archivo.chunkSize);
  printf("Format: %.*s\n", 4, archivo.format);
  printf("Subchunk 1 ID: %.*s\n", 4, archivo.subchunk1ID);
  printf("Subchunk 1 size: %d\n", archivo.subchunk1Size);
  printf("Audio format: %d\n", archivo.audioFormat);
  printf("Number of channels: %d\n", archivo.numChannels);
  printf("Sample rate: %d\n", archivo.sampleRate);
  printf("Byte rate: %d\n", archivo.byteRate);
  printf("Block align: %d\n", archivo.blockAlign);
  printf("Bits per sample: %d\n", archivo.bitsPerSample);
  printf("Subchunk 2 ID: %.*s\n", 4, archivo.subchunk2ID);
  printf("Subchunk 2 size: %d\n", archivo.subchunk2Size);

  
    // Calcular el número de muestras de audio
    num_samples = (archivo.chunkSize - 36) * 8         
    /archivo.bitsPerSample /archivo.numChannels;

  
    // Solicitar el tiempo a avanzar al usuario
    printf("Introduce el tiempo a avanzar (en segundos): ");
    scanf("%lf", &time_to_advance);

    // Calcular el número de bytes a avanzar
    while (time_to_advance<=3)
      {
        bytes_to_advance = time_to_advance * archivo.sampleRate * archivo.blockAlign;  
        printf("Bytes avanzados: %d\n", bytes_to_advance);
        ++time_to_advance;
      }


  // Función para calcular la DFT de un vector de muestras de audio
      for (int k = 0; k < num_samples; k+bytes_to_advance) {
          y[k] = 0;
          for (int n = 0; n < num_samples; n++) {
              y[k] += w[n] * cos(2 * M_PI * k * n / num_samples);
          }
      }

  
  printf("    Hz");
  printf("     |");
  
  for (int m = 0; m < num_samples; m++) {
    switch (y[m]) {
        case (y[m]==16000):
            switch (y[m]) {
                case (y[m] > 0 && y[m] <= 25): 
                printf("16k  |||]"); //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                printf("16k  |||||||]")  //2
                break;

                case (y[m] > 50 && y[m]] <= 75):
                printf("16k  |||||||||||]");  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                printf("16k  |||||||||||||||]");  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                printf("16k  ||||||||||||||||||||]");  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                printf("16k  |||||||||||||||||||||||||]");  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                printf("16k  ||||||||||||||||||||||||||||||]") ;  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                printf("16k  |||||||||||||||||||||||||||||||||||]");   //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                printf("16k  ||||||||||||||||||||||||||||||||||||||||]");   //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                printf("16k  |||||||||||||||||||||||||||||||||||||||||||||||]");  
                break;

                case (y[m] > 250 && y[m] <= 255): 
                printf("16k  ||||||||||||||||||||||||||||||||||||||||||||||||]");   
                break;

                default: 
                    printf("16k  |");  
                    break;

            }
        break;

        case (w[y[m]==14000):
            switch (y[n])  {
                case (y[m] > 0 && y[m] <= 25): 
                print("14k  |||]");  //1
                break;

                case (y[m] > 25 && y[m]] <= 50):
                print("14k  |||||||]")  //2
                break;

                case (y[m] > 50 && y[m] <= 75):
                print("14k  |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("14k  |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("14k  ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("14k  |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[n]y[m] <= 175):
                print("14k  ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("14k  |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("14k  ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("14k  |||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && yy[m] <= 255): 
                print("14k  ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("14k  |") 
                    break;


            }
        break;

        case (y[m]==12000):
            switch (yy[m])  {
                case (y[m] > 0 && y[m] <= 25): 
                print("12k  |||]") //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                print("12k  |||||||]")  //2
                break;

                case (y[m] > 50 && y[m]] <= 75):
                print("12k  |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("12k  |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("12k  ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("12k  |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                print("12k  ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("12k  |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("12k  ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("12k  |||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && y[m] <= 255): 
                print("12k  ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("12k  |") 
                    break;


            }
        break;

        case (w[m]==6000):
            switch (y[m])  {
                case (y[m] > 0 && y[m] <= 25): 
                print("6k   |||]") //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                print("6k   |||||||]")  //2
                break;

                case (y[m] > 50 && y[m] <= 75):
                print("6k   |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("6k   |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("6k   ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("6k   |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                print("6k   ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("6k   |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("6k   ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("|||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && y[m] <= 255): 
                print("6k   ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("6k   |") 
                    break;


            }
        break;  

        case (w[m]==3000):
            switch (y[m])  {
                case (y[m] > 0 && y[m] <= 25): 
                print("3k   |||]") //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                print("3k   |||||||]")  //2
                break;

                case (y[m] > 50 && y[m] <= 75):
                print("3k   |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("3k   |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("3k   ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("3k   |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                print("3k   ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("3k   |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("3k   ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("3k   |||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && y[m] <= 255): 
                print("3k   ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("|") 
                    break;


            }
        break;

        case (w[m]==1000):
            switch (y[m]) {
                case (y[m] > 0 && y[m] <= 25): 
                print("1k   |||]") //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                print("1k   |||||||]")  //2
                break;

                case (y[m] > 50 && y[m] <= 75):
                print("1k   |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("1k   |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("1k   ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("1k   |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                print("1k   ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("1k   |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("1k   ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("1k   |||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && y[m] <= 255): 
                print("1k   ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("1k   |") 
                    break;


            }
        break;
        
        case (w[m]==600):
            switch (y[m])  {
                case (y[m] > 0 && y[m] <= 25): 
                print("600  |||]") //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                print("600  |||||||]")  //2
                break;

                case (y[m] > 50 && y[m] <= 75):
                print("600  |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("600  |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("600  ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("600  |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                print("600  ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("600  |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("600  ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("600  |||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && y[m] <= 255): 
                print("600  ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("600  |") 
                    break;


            }
        break;

        case (w[m]==310):
            switch (y[m])  {
                case (y[m] > 0 && y[m] <= 25): 
                print("310  |||]") //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                print("310  |||||||]")  //2
                break;

                case (y[m] > 50 && y[m] <= 75):
                print("310  |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("310  |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("310  ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("310  |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                print("310  ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("310  |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("310  ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("310  |||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && y[m] <= 255): 
                print("310  ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("310  |") 
                    break;


            }
        break;

        case (w[m]==170):
            switch (y[m]) {
                case (y[m] > 0 && y[m] <= 25): 
                print("170  |||]") //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                print("170  |||||||]")  //2
                break;

                case (y[m] > 50 && y[m] <= 75):
                print("170  |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("170  |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("170  ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("170  |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                print("170  ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("170  |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("170  ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("170  |||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && y[m] <= 255): 
                print("170  ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("170  |") 
                    break;


            }
        break;

        case (w[m]==60):
            switch (y[m])  {
                case (y[m] > 0 && y[m] <= 25): 
                print("60   |||]") //1
                break;

                case (y[m] > 25 && y[m] <= 50):
                print("60   |||||||]")  //2
                break;

                case (y[m] > 50 && y[m] <= 75):
                print("60   |||||||||||]")  //3
                break;

                case (y[m] > 75 && y[m] <= 100):
                print("60   |||||||||||||||]")  //4
                break;

                case (y[m] > 100 && y[m] <= 125):
                print("60   ||||||||||||||||||||]")  //5
                break;

                case (y[m] >= 125 && y[m] <= 150):
                print("60   |||||||||||||||||||||||||]")  //6
                break;

                case (y[m] > 150 && y[m] <= 175):
                print("60   ||||||||||||||||||||||||||||||]")  //7
                break;

                case (y[m] > 175 && y[m] <= 200):
                print("60   |||||||||||||||||||||||||||||||||||]")  //8
                break;

                case (y[m] > 200 && y[m] <= 225):
                print("60   ||||||||||||||||||||||||||||||||||||||||]")  //9
                break;

                case (y[m] > 225 && y[m] <= 250): 
                print("|||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                case (y[m] > 250 && y[m] <= 255): 
                print("60   ||||||||||||||||||||||||||||||||||||||||||||||||]")  //10
                break;

                default: 
                    print("60   |") 
                    break;


            }
        break;

        default: 
            break;

    }

    
      }
    print("     |-------------------------------------------------------- ");
    print("     0  25   50  75  100  125  150  175  200  225  250  275");

  
  
    // Liberar la memoria y cerrar el archivo
    free(data);
    fclose(w);

    return 0;
}

