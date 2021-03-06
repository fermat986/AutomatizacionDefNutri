#ifndef IMAGENPRO_H
#define IMAGENPRO_H
#include <QString>
#include <QImage>
#include <QPixmap>
#include <QVector>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <QFile>
#include <QTextStream>
#include <math.h>
using namespace std;

class imagenPro
{

    /**
     * @param image imagen de entrada para realizarle operaciones
     * @param imageProcess imagen de salida procesada
     * @param histograma de la imagen
     * @param red valores de gama de la matriz de rojos
     * @param green valores de gama de la matriz de verdes
     * @param blue valores de gama de la matriz de azul
     * @param gray valores de cuantizacion en gris de la imagen
     * @param tabla valores de tabla
     */
    QImage *image;
    QImage *imageProcess;
    int histograma[256];
    QVector <QVector <int> > red;
    QVector <QVector <int> > green;
    QVector <QVector <int> > blue;
    QVector <QVector <int> > gray;
    QVector <QVector <int> > valoresE;
    QVector <QVector <int> > valoresEx;
    QVector <QVector <int> > valoresEy;
    QVector <QVector <int> > gradiente;
    QVector <QRgb> tabla;
public:
    /**
      *
      */
    imagenPro();
    /** Constructor del curso
      * miRuta Qstring  que contiene la ruta  de localizacion de la imagen
      */
    imagenPro(QString miRuta);

    /**
     * @brief calcularHistograma calcula el histograma de la imagen
     */
    void calcularHistograma(QImage imagen);


    //void mostrarHisto();


    /**
     * @brief sumarCon le suma un valor dado a los valores rgb de la imagen
     * @param val valor int a sumar a cada pixel rgb
     */
    void sumarCon(int val);

    /**
     * @brief getChannels Inicializa los valores de cada matrzi rgb
     */
    void getChannels();

    /**
     * @brief binarizarImg convierte los valores de una imagen en 1 o 0 dependiendo del umbral
     * @param umbral int que define en que punto se hara la umbralizacion
     */
    void binarizarImg(int umbral);

    /**
     * @brief multiThresholding metodo para dividir la cuantizacion en tres niveles diferentes
     */
    void multiThresholding();
    void createPGM();

    /**
     * @brief getHisto retorna un puntero del histograma
     * @return int* como un apuntador del histograma
     */
    int* getHisto();

    void leerArchPP(QString ruta);

    /**
     * @brief resultado devuelve una imagen con el resultado de las operaciones sobre la imagen
     * @return QPixmap de la imagen
     */
    QPixmap resultado();


    void filtroMediana();

    int operMediana(int i, int j);

    void filtroSobel();

    int operacionConvolucion(float valor[3][3], int i, int j);


};

#endif // IMAGENPRO_H
