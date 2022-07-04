using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Net;
using System.Net.Sockets;

public class TCPClient : MonoBehaviour
{
    // Start is called before the first frame update
    public static TCPClient instance;
    public TcpClient client;

    void Awake()
    {
        instance = this;
        DontDestroyOnLoad(gameObject);
    }
}
