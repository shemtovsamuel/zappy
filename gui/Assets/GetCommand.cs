using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Net.Sockets;
using System.Text;

public class GetCommand : MonoBehaviour
{

    public GeneratorQuadrillage generator;
    NetworkStream stream;
    string buffer = "";

    void Start()
    {
        stream =  TCPClient.instance.client.GetStream();
    }

    void Update()
    {
        if (!stream.DataAvailable)
            return;

        Byte[] data = new Byte[2626];
        String responseData = String.Empty;
        Int32 bytes = stream.Read(data, 0, data.Length);
        responseData = System.Text.Encoding.ASCII.GetString(data, 0, bytes);
        responseData = responseData.Substring(0, bytes);
        // print("Received: " + responseData);
        buffer += responseData;


        while (buffer.Contains("\n"))
        {
            int index = buffer.IndexOf("\n");
            string command = buffer.Substring(0, index);
            buffer = buffer.Substring(index + 1);
            print("COMMAND: " + command);
            parseCommand(command);
        }
    }

    void parseCommand(string command)
    {
        int nbBoxwidth = 0;
        int nbBoxheight = 0;

        if (command.StartsWith("msz "))
        {
            command = command.Replace("msz ", "");
            string[] size = command.Split(' ');
            nbBoxwidth = Convert.ToInt32(size[0]);
            nbBoxheight = Convert.ToInt32(size[1]);
            generator.nbBoxWidth = nbBoxwidth;
            generator.nbBoxHeigth = nbBoxheight;
            generator.Generate();
        }

        if (command.StartsWith("bct "))
        {
            command = command.Replace("bct ", "");
            string[] position = command.Split(' ');
            int xR = Convert.ToInt32(position[0]);
            int yR = Convert.ToInt32(position[1]);
            int foodR = Convert.ToInt32(position[2]);
            int linemateR = Convert.ToInt32(position[3]);
            int deraumereR = Convert.ToInt32(position[4]);
            int siburR = Convert.ToInt32(position[5]);
            int mendianeR = Convert.ToInt32(position[6]);
            int phirasR = Convert.ToInt32(position[7]);
            int thystameR = Convert.ToInt32(position[8]);
            generator.GenerateRessource(xR, yR, foodR, linemateR, deraumereR, siburR, mendianeR, phirasR, thystameR);
        }

        if (command.StartsWith("pnw "))
        {
            command = command.Replace("pnw ", "");
            string[] player = command.Split(' ');
            int idP = Convert.ToInt32(player[0]);
            int xP = Convert.ToInt32(player[1]);
            int yP = Convert.ToInt32(player[2]);
            int orientationP = Convert.ToInt32(player[3]);
            int levelP = Convert.ToInt32(player[4]);
            generator.GeneratePlayer(idP, xP, yP, orientationP);
        }
    }
}
