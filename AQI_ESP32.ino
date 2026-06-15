#include "model_regresi.h"

void setup()
{
    Serial.begin(115200);
    delay(2000);

    double input[5] =
    {
        60,
        10,
        30,
        80,
        20
    };

    double hasil = score(input);

    Serial.print("Prediksi MAX = ");
    Serial.println(hasil);

    if (hasil <= 50)
        Serial.println("Kategori: BAIK");
    else if (hasil <= 100)
        Serial.println("Kategori: SEDANG");
    else if (hasil <= 200)
        Serial.println("Kategori: TIDAK SEHAT");
    else
        Serial.println("Kategori: SANGAT TIDAK SEHAT");
}

void loop()
{
}