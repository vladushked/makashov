#include <iostream>
#include <string>

#include <stdint.h>

using namespace std;

//05430D083B183F91BCD8193EDF4DE94F00080015BCA408C0163BFB4DAB173F80F5081BC16EA4371cc12d31271d42513d4f4a000000004b000000004c00000000
//(05 430D083B)(18 3F91BCD8)(19 3EDF4DE9)(4F 00)(08 00)(15 BCA408C0)(16 3BFB4DAB)(17 3F80F508)(1B C16EA437)(1c c12d3127)(1d 42513d4f)(4a 00000000)(4b 00000000)(4c 00000000)
struct component
{
    float kHeading,
    kPitch,
    kRoll,
    kTemperature,
    kAccelX,
    kAccelY,
    kAccelZ,
    kMagX,
    kMagY,
    kMagZ,
    kGyroX,
    kGyroY,
    kGyroZ,
    kQuaternion[4];

    uint8_t kHeadingStatus;

    bool kDistortion,
    kCalStatus;
};


uint8_t readStringHex(size_t s_counter, string s_data);
float readFloat(size_t s_counter, uint8_t* s_data);
void stringToHex(string s_data, size_t s_length, uint8_t* ptr);
void readParcel(uint8_t* s_data, size_t s_length);
void show();

component parcel;

int main()
{
    string data;

    //cout << "Введите посылку" << endl;   //ввод посылки
    //cin >> data;

    data = "05430D083B183F91BCD8193EDF4DE94F00080015BCA408C0163BFB4DAB173F80F5081BC16EA4371cc12d31271d42513d4f4a"
           "0000004b000000004c00000000";
    //cout << data << endl;

    size_t len = data.length();
    //cout << len << endl;

    uint8_t* hex_data = new uint8_t[len/2]; // выделили динамическую память

    /*
    for (size_t i = 0; i < len/2; i++){
        cout << hex_data[i] << "_";
    }
    cout << endl;
    */

    stringToHex(data,len,hex_data); // переводим строку в набор байтов

    for (size_t i = 0; i < len/2; i++){
        cout << hex_data[i] << "_";
    }
    cout << endl << endl;

    readParcel(hex_data, len/2);
    show();

    delete [] hex_data;
    return 0;
}

uint8_t readStringHex(size_t s_counter, string s_data) // считывание hex
{
    uint8_t s_hex = 0;

    for (size_t i = 0; i < 2; i++)
    {
        uint8_t j;

        if ((s_data[s_counter + i] > 47) and (s_data[s_counter + i] < 58)) // цифры
        {
            j = s_data[s_counter + i] - 48;
        }
        else if ((s_data[s_counter + i] > 64) and (s_data[s_counter + i] < 91)) // заглавные буквы
        {
            j = s_data[s_counter + i] - 65 + 10;
        }
        else if ((s_data[s_counter + i] > 96) and (s_data[s_counter + i] < 123)) //прописные буквы
        {
            j = s_data[s_counter + i] - 97 + 10;
        }
        if (i == 0) s_hex = j << 4;
        else s_hex += j;
    }
    return s_hex;
}

void stringToHex(string s_data,size_t s_length, uint8_t* ptr)
{

    for (size_t i = 0; i < s_length;i+=2)
    {
        ptr[i/2] = readStringHex(i,s_data);
    }
}

void readParcel(uint8_t* s_data, size_t s_length)
{

    for (size_t i = 0; i < s_length;)
    {
        int id = s_data[i];
        i++;
        switch (id){
        case 5:
            parcel.kHeading = readFloat(i,s_data);
            i += 4;
            break;
        case 24:
            parcel.kPitch = readFloat(i,s_data);
            i += 4;
            break;
        case 25:
            parcel.kRoll = readFloat(i,s_data);
            i += 4;
            break;
        case 79:
            parcel.kHeadingStatus = s_data[i];
            i++;
            break;
        case 77:
            for (size_t j = 0; j < 4; j++)
            {
                parcel.kQuaternion[j] = readFloat(i+j,s_data);
            }
            i += 16;
            break;
        case 7:
            parcel.kTemperature= readFloat(i,s_data);
            i += 4;
            break;
        case 8:
            parcel.kDistortion = s_data[i];
            i += 1;
            break;
        case 9:
            parcel.kCalStatus = s_data[i];
            i += 1;
            break;
        case 21:
            parcel.kAccelX = readFloat(i,s_data);
            i += 4;
            break;
        case 22:
            parcel.kAccelY= readFloat(i,s_data);
            i += 4;
            break;
        case 23:
            parcel.kAccelZ= readFloat(i,s_data);
            i += 4;
            break;
        case 27:
            parcel.kMagX = readFloat(i,s_data);
            i += 4;
            break;
        case 28:
            parcel.kMagY = readFloat(i,s_data);
            i += 4;
            break;
        case 29:
            parcel.kMagZ = readFloat(i,s_data);
            i += 4;
            break;
        case 74:
            parcel.kGyroX = readFloat(i,s_data);
            i += 4;
            break;
        case 75:
            parcel.kGyroY = readFloat(i,s_data);
            i += 4;
            break;
        case 76:
            parcel.kGyroZ = readFloat(i,s_data);
            i += 4;
            break;
        default:
            cout << "WRONG ID OR YOU'R STUPID";
        }
    }

}


float readFloat(size_t s_counter, uint8_t* s_data)
{
    uint8_t hex[4];
    float s_float;

    /*
    for (size_t i = 0; i < 64; i++){
        cout << s_data[i] << "_";
    }
    cout << endl << endl;
    */

    for (int i = 3; i > -1; i--)
    {
          hex[3-i] = s_data[s_counter + i];
    }
    s_float = *reinterpret_cast<float*>(hex);
    return s_float;
}

void show()
{
    int headingstat = parcel.kHeadingStatus;
    cout << "Heading:\t\t" << parcel.kHeading <<  endl;
    cout << "Pitch:\t\t\t" << parcel.kPitch << endl;
    cout << "Roll:\t\t\t" << parcel.kRoll << endl;
    cout << "kHeadingStatus:\t\t" << headingstat << endl;
    cout << "kQuaternion:\t\t" << parcel.kQuaternion[0] << endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "\t\t\t" << parcel.kQuaternion[i] << endl;
    }
    cout << "kTemperature:\t\t" << parcel.kTemperature << endl;
    cout << "kDistortion:\t\t" << parcel.kDistortion << endl;
    cout << "kCalStatus:\t\t" << parcel.kCalStatus << endl;
    cout << "kAccelX:\t\t" << parcel.kAccelX << endl;
    cout << "kAccelY:\t\t" << parcel.kAccelY << endl;
    cout << "kAccelZ:\t\t" << parcel.kAccelZ << endl;
    cout << "kMagX:\t\t\t" << parcel.kMagX << endl;
    cout << "kMagY:\t\t\t" << parcel.kMagY << endl;
    cout << "kMagZ:\t\t\t" << parcel.kMagZ << endl;
    cout << "kGyroX:\t\t\t" << parcel.kGyroX << endl;
    cout << "kGyroY:\t\t\t" << parcel.kGyroY << endl;
    cout << "kGyroZ:\t\t\t" << parcel.kGyroZ << endl << endl;
}
