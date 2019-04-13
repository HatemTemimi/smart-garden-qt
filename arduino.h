#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QLCDNumber>
class Arduino
{
public:
    Arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();
    QString read_HT_arduino();
    QString readSerial();
    void updateTemperature(QString);
    QString gethumidity(){
        return humidity;}
private:
    QSerialPort * serial;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
    static const quint16 arduino_uno_vendor_id=6790;
    static const quint16 arduino_uno_producy_id=29987;
    QString humidity;
    QString serialBuffer;
    QString parsed_data;

};



#endif // ARDUINO_H
