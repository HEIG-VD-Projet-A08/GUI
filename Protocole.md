# Description 

Ce protocole a pour but d'interfacer les différents acteurs de notre système, c'est à dire l'interface graphique qui va envoyer les paramètres donnés par l'utilisateur et recevoir des résultats, l'algorithme évolutif pour la génération de mot et l'algorithme pour traitement de ces résultats.

Le serveur sera implémenter de manière stateless. Les transferts d'options ou d'information se fera de manière sérialisée avec un fichier **.xml**. 



# Établissement de la communication 

Pour établir la connexion avec le serveur, Le client débutera la communication avec le message **Hello Server**.
Nous ne gérons pas si plusieurs clients se connectent au serveur. 

```sequence
Client->>Server: Send "Hello Server"
```

# Commandes implémentées

Pour toutes ces commandes on considère que le client à déjà début la communication. 

## Début du processus (manque les options possibles)

Pour débuter un calcul, le client envoie la commande **START\n <fichier.xml>** ou fichier.xml est l'ensemble des options dont le programme à besoin pour fonctionner. 

```sequence
Client->>Server: Send "START\n"
Client->>Server: Send "options.xml"
```

## Mise en pause du processus en cours 

### Avec perte de données 

Si pour une raison ou une autre le client désire terminer le processus en cours, il envoie la commande **STOP**. Tout le processus sera alors perdu. 
```sequence
Client->>Server: Send "STOP\n"
Server->>Client: Send "STOP experiment"
```

### Sans perte de données 

Dans le cas ou le client ne veut pas perdre les résultats intermédiaires, Il peut envoyer la commande **STOP -R**  qui effectuera d'abord une sauvegarde de résultat intermédiaire, comme la commande **RES**, puis ensuite arrêtera le processus.

```sequence
Client->>Server: Send "STOP -R"
Server->>Client: Send "STOP experiment,intermediate result in Result.xml "
```

## Résultat intermédiaire
À chaque itération le serveur envoie les données à afficher dans le graphique sous la forme d'un fichier xml.
```sequence
Server->>Client: Send Result.xml
```

## Terminaison d'une communication existante

### Par le client

Si le client effectue la commande **BYE**, le serveur coupera la communication sans envoyer de message. 

**BYE**

```sequence
Client->>Server: Send "BYE"
```


## Commande Fausse ou erreur de paramètres

Dans le cas ou le client enverrait une commande fausse, qui n'existe pas ou avec de mauvais paramètres, le serveur répondra avec le message **ERROR Bad Message** et terminera la connexion. 

```sequence
Client->>Server: Send "RET"
Server->>Client: Send "ERROR Bad Message"
```
