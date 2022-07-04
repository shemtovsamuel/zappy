using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class GeneratorQuadrillage : MonoBehaviour
{
    public GameObject box;
    public GameObject food;
    public GameObject linemate;
    public GameObject deraumere;
    public GameObject sibur;
    public GameObject mendiane;
    public GameObject phiras;
    public GameObject thystame;
    public GameObject player;


    public int nbBoxWidth;
    public int nbBoxHeigth;

    Vector3 scaleCase;
    Vector3 scaleRessource;
    Vector3 scalePlayer;

    float scaleWidth;
    float scaleHeigth;
    float size;

    Dictionary<int, GameObject> PlayerStock = new Dictionary<int, GameObject>();

    public void GeneratePlayer(int idP, int xPos, int yPos, int orienationP)
    {
        scalePlayer = player.gameObject.transform.localScale;
        scalePlayer.x = (1.5f / scaleCase.x) * Math.Min(scaleWidth, scaleHeigth);
        scalePlayer.y = (1.5f / scaleCase.y) * Math.Min(scaleWidth, scaleHeigth);
        scalePlayer.z = (1.5f / scaleCase.z) * Math.Min(scaleWidth, scaleHeigth);
        player.gameObject.transform.localScale = scalePlayer;

        GameObject p = Instantiate(box, new Vector3(transform.position.x - (xPos * scaleWidth) - (scaleCase.x / 2), transform.position.y + (scaleCase.y / 2), transform.position.z + (yPos * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, this.transform);
        GameObject newPlayer = Instantiate(player, new Vector3(transform.position.x - ((xPos) * scaleWidth) - (scaleCase.x / 2), transform.position.y + 1.5f, transform.position.z + (yPos * scaleHeigth) + (scaleCase.z / 2)), Quaternion.Euler(0, orienationP, 0), p.transform);
        PlayerStock.Add(idP, newPlayer);
    }

    public void GenerateRessource(int xRessource, int yRessource, int nbFood, int nbLinemate, int nbDeraumere, int nbSibur, int nbMendiane, int nbPhiras, int nbThystame)
    {
        GameObject newC = Instantiate(box, new Vector3(transform.position.x - (xRessource * scaleWidth) - (scaleCase.x / 2), transform.position.y + (scaleCase.y / 2), transform.position.z + (yRessource * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, this.transform);

        if (nbFood > 0)
            Instantiate(food, new Vector3(transform.position.x - ((xRessource) * scaleWidth) - (scaleCase.x / 2), transform.position.y + 1.5f, transform.position.z + (yRessource * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, newC.transform);
        if (nbLinemate > 0)
            Instantiate(linemate, new Vector3(transform.position.x - ((xRessource + 0.3f) * scaleWidth) - (scaleCase.x / 2), transform.position.y + 1.5f, transform.position.z + ((yRessource - 0.3f) * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, newC.transform);
        if (nbDeraumere > 0)
            Instantiate(deraumere, new Vector3(transform.position.x - ((xRessource - 0.3f) * scaleWidth) - (scaleCase.x / 2), transform.position.y + 1.5f, transform.position.z + ((yRessource - 0.3f) * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, newC.transform);
        if (nbSibur > 0)
            Instantiate(sibur, new Vector3(transform.position.x - ((xRessource + 0.3f) * scaleWidth) - (scaleCase.x / 2), transform.position.y + 1.5f, transform.position.z + ((yRessource + 0.3f) * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, newC.transform);
        if (nbMendiane > 0)
            Instantiate(mendiane, new Vector3(transform.position.x - ((xRessource - 0.3f) * scaleWidth) - (scaleCase.x / 2), transform.position.y + 1.5f, transform.position.z + ((yRessource + 0.3f) * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, newC.transform);
        if (nbPhiras > 0)
            Instantiate(phiras, new Vector3(transform.position.x - ((xRessource) * scaleWidth) - (scaleCase.x / 2), transform.position.y + 1.5f, transform.position.z + ((yRessource + 0.3f) * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, newC.transform);
        if (nbThystame > 0)
            Instantiate(thystame, new Vector3(transform.position.x - ((xRessource) * scaleWidth) - (scaleCase.x / 2), transform.position.y + 1.5f, transform.position.z + ((yRessource - 0.3f) * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, newC.transform);
    }

    public void Generate()
    {
        scaleWidth = 50.0f / nbBoxWidth;
        scaleHeigth = 50.0f / nbBoxHeigth;

        scaleCase = box.gameObject.transform.localScale;
        scaleCase.x = scaleWidth;
        scaleCase.z = scaleHeigth;
        box.gameObject.transform.localScale = scaleCase;

        scaleRessource = food.gameObject.transform.localScale;
        scaleRessource.x = (0.1f / scaleCase.x) * Math.Min(scaleWidth, scaleHeigth);
        scaleRessource.z = (0.1f / scaleCase.z) * Math.Min(scaleWidth, scaleHeigth);
        food.gameObject.transform.localScale = scaleRessource;

        scaleRessource = linemate.gameObject.transform.localScale;
        scaleRessource.x = (0.1f / scaleCase.x) * Math.Min(scaleWidth, scaleHeigth);
        scaleRessource.z = (0.1f / scaleCase.z) * Math.Min(scaleWidth, scaleHeigth);
        linemate.gameObject.transform.localScale = scaleRessource;

        scaleRessource = deraumere.gameObject.transform.localScale;
        scaleRessource.x = (0.1f / scaleCase.x) * Math.Min(scaleWidth, scaleHeigth);
        scaleRessource.z = (0.1f / scaleCase.z) * Math.Min(scaleWidth, scaleHeigth);
        deraumere.gameObject.transform.localScale = scaleRessource;

        scaleRessource = sibur.gameObject.transform.localScale;
        scaleRessource.x = (0.1f / scaleCase.x) * Math.Min(scaleWidth, scaleHeigth);
        scaleRessource.z = (0.1f / scaleCase.z) * Math.Min(scaleWidth, scaleHeigth);
        sibur.gameObject.transform.localScale = scaleRessource;

        scaleRessource = mendiane.gameObject.transform.localScale;
        scaleRessource.x = (0.1f / scaleCase.x) * Math.Min(scaleWidth, scaleHeigth);
        scaleRessource.z = (0.1f / scaleCase.z) * Math.Min(scaleWidth, scaleHeigth);
        mendiane.gameObject.transform.localScale = scaleRessource;

        scaleRessource = phiras.gameObject.transform.localScale;
        scaleRessource.x = (0.1f / scaleCase.x) * Math.Min(scaleWidth, scaleHeigth);
        scaleRessource.z = (0.1f / scaleCase.z) * Math.Min(scaleWidth, scaleHeigth);
        phiras.gameObject.transform.localScale = scaleRessource;

        scaleRessource = thystame.gameObject.transform.localScale;
        scaleRessource.x = (0.1f / scaleCase.x) * Math.Min(scaleWidth, scaleHeigth);
        scaleRessource.z = (0.1f / scaleCase.z) * Math.Min(scaleWidth, scaleHeigth);
        thystame.gameObject.transform.localScale = scaleRessource;

        for (int i = 0; i < nbBoxHeigth; i++) {
            for (int j = 0; j < nbBoxWidth; j++) {
                GameObject c = Instantiate(box, new Vector3(transform.position.x - (j * scaleWidth) - (scaleCase.x / 2), transform.position.y + (scaleCase.y / 2), transform.position.z + (i * scaleHeigth) + (scaleCase.z / 2)), Quaternion.identity, this.transform);
            }
        }

    //    GeneratePlayer(0, 2, 2, 90);
    }

    void Update()
    {
    }
}