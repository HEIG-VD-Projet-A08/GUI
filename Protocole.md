

# Description 

Ce protocole a pour but d'interfacer les différents acteurs de notre système, c'est à dire l'interface graphique qui va envoyer les paramètres donnés par l'utilisateur et recevoir des résultats, l'algorithme évolutif pour la génération de mot et l'algorithme pour traitement de ces résultats.

Le serveur sera implémenter de manière stateless. Les transferts d'options ou d'informations entre les deux parties se fera de manière sérialisée avec un fichier **.xml**. 

# Établissement de la communication 

Pour établir la connexion avec le serveur, Le client débutera la communication avec le message **Hello Server\n**.
Nous ne gérons pas si plusieurs clients se connectent au serveur. À noter que le retour à la ligne après le Hello Server est attendu.

```sequence
Client->>Server: Send "Hello Server"
```

# Commandes implémentées

Pour toutes ces commandes on considère que le client à déjà début la communication.  

## Début du processus (manque les options possibles)

Pour débuter un calcul, le client envoie la commande **START\n <fichier.xml>** ou fichier.xml est l'ensemble des options dont le programme à besoin pour fonctionner.  La DTD qui se trouve plus bas explique le format de l'XML à envoyer. À noter que le retour à la ligne après le START est attendu.

```sequence
Client->>Server: Send "START"
Client->>Server: Send "options.xml"
```

```dtd
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE Option [
	<!ELEMENT Nb_words (#PCDATA)>
	<!ELEMENT Nb_char_Max (#PCDATA)>
    <!ELEMENT Nb_char_Min (#PCDATA)>
	<!ELEMENT Nb_iter (#PCDATA)>
]>
```



## Mise en pause du processus en cours 

### Avec perte de données 

Si pour une raison ou une autre le client désire terminer le processus en cours, il envoie la commande **STOP**\n. Cela va indiquer au serveur qu'il faut arrêter les calculs et que le client ne prendra plus en compte d'éventuels résultat envoyés après cette commande. À noter que le retour à la ligne après le STOP est attendu.
```sequence
Client->>Server: Send "STOP"
```

### Sans perte de données 

Dans le cas ou le client ne veut pas perdre les résultats intermédiaires, Il peut envoyer la commande **STOP -R\n**  qui indiquera au serveur que nous allons recevoir encore un résultat. Ensuite seulement le client va envoyer **BYE\n** pour terminer la connexion. ce processus peut durer plusieurs minutes. car cela dépend de l'itération côté algorithme. À noter que les retour à la ligne après le STOP -R  et le BYE sont attendu.

```sequence
Client->>Server: Send "STOP -R"
Server->>Client: Send "resul.xml"
Client->>Server: Send "BYE"
```

## Résultat intermédiaire
À chaque itération le serveur envoie les données à afficher dans le graphique sous la forme d'un fichier xml dont la DTD se trouve ci-dessous. Il n'y a pas d'accusé de réception de la part du client pour éviter un trafic de message qui obligerais le serveur à traiter le message. 
```sequence
Server->>Client: Send Result.xml
```

```dtd
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE result [
	<!ELEMENT it (#PCDATA)>
	<!ELEMENT test (#PCDATA)>
    <!ELEMENT predict (#PCDATA)>
	<!ELEMENT word (#PCDATA)>
]>
```



## Terminaison d'une communication existante

**BYE**

Quand le client envoie **BYE\n** cela indique au serveur qu'il va terminer la connexion. 

```sequence
Client->>Server: Send "BYE"
```


## Commande Fausse ou erreur de paramètres

Dans le cas ou le client enverrait une commande fausse, qui n'existe pas ou avec de mauvais paramètres, le serveur répondra avec le message **ERROR Bad Message** et terminera la connexion. Dans le cadre de la GUI cette commande n'est pas implémentée car il n'est pas possible de d'avoir des commandes qui sont fausses. 

```sequence
Client->>Server: Send "RET"
Server->>Client: Send "ERROR Bad Message"
```
