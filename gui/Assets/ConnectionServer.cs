using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Net.Sockets;
using System.Text;
using UnityEngine.SceneManagement;

public class ConnectionServer : MonoBehaviour
{
    public int port = 8080;
    public string serverIP = "127.0.0.1";

    public void setIP(string ip)
    {
        serverIP = ip;
    }

    public void setPort(string port)
    {
        this.port = Convert.ToInt32(port);
    }

    public void Connection()
    {
        try
        {
            // var client = new TcpClient(serverIP, port);
            TCPClient.instance.client = new TcpClient(serverIP, port);

            NetworkStream ns = TCPClient.instance.client.GetStream();

            byte[] bytes = new byte[1024];
            int bytesRead = ns.Read(bytes, 0, bytes.Length);

            print(Encoding.ASCII.GetString(bytes,0,bytesRead));
            ns.Write(System.Text.Encoding.ASCII.GetBytes("gui\n"), 0, "gui\n".Length);
            ns.Write(System.Text.Encoding.ASCII.GetBytes("GRAPHIC\n"), 0, "GRAPHIC\n".Length);
            Debug.Log("Connected to server :)");
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);

        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
            Debug.Log("Could not connect to server :/");
        }
    }
}
