
#ifndef CLIENTTCP_H
#define CLIENTTCP_H
#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QtCore>

class ClientTcp : public QObject
{
Q_OBJECT
private:
    QObject *parent;
    QTcpSocket *socket;
    QString add;
    int port;

public:
    /**
     * @brief ClientTcp constructeur de la classe
     * @param parent ClientTcp classe créant l'instance client tcp
     * @param ipAdd adresse IP
     * @param port port de connection
     */
    ClientTcp(QObject *parent, QString ipAdd, int port);
    /**
      * @brief destructeur de la classe, ferme aussi le socket
      */
    ~ClientTcp();

    /**
     * @brief sendGreetings établit une connexion avec le serveur
     */
    void sendGreetings();
    /**
     * @brief sendData envoie un fichier XML pour la configuration de l'algorithme
     * @param file fichier à envoyer
     */
    void sendData(QFile &file);


signals:
    /**
     * @brief readResultXML reçoit les résultats du serveur sous format XML
     */
    void readResultXML();

public slots:
    /**
     * @brief readyRead signal lors de la réception d'un message du serveur
     */
    void readyRead();
};

#endif // CLIENTTCP_H
