using BepInEx;
using HarmonyLib;
using UnityEngine;
using UnityEngine.Networking;

[BepInPlugin("turtlerec.connector", "TurtleRec Connector", "0.3.0")]
public class Plugin : BaseUnityPlugin
{
    public static string BackendUrl = "http://127.0.0.1:3000";

    void Awake()
    {
        Logger.LogInfo("TurtleRec Connector 0.3 loaded");
        Logger.LogInfo("Backend URL: " + BackendUrl);
        new Harmony("turtlerec.connector").PatchAll();
    }
}

[HarmonyPatch(typeof(UnityWebRequest), "SendWebRequest")]
public class SendPatch
{
    static void Prefix(UnityWebRequest __instance)
    {
        string oldUrl = __instance.url;

        if (string.IsNullOrEmpty(oldUrl)) return;

        string newUrl = oldUrl
            .Replace("https://api.rec.net", Plugin.BackendUrl)
            .Replace("http://api.rec.net", Plugin.BackendUrl)
            .Replace("https://accounts.rec.net", Plugin.BackendUrl)
            .Replace("http://accounts.rec.net", Plugin.BackendUrl)
            .Replace("https://rec.net", Plugin.BackendUrl)
            .Replace("http://rec.net", Plugin.BackendUrl)
            .Replace("https://images.rec.net", Plugin.BackendUrl)
            .Replace("http://images.rec.net", Plugin.BackendUrl)
            .Replace("https://match.rec.net", Plugin.BackendUrl)
            .Replace("http://match.rec.net", Plugin.BackendUrl);

        if (newUrl != oldUrl)
        {
            __instance.url = newUrl;
            Debug.Log("[TurtleRecConnector] Redirected: " + oldUrl + " -> " + newUrl);
        }

        string lower = __instance.url.ToLower();

        if (lower.Contains("login") || lower.Contains("auth") || lower.Contains("recnet") || lower.Contains("photo") || lower.Contains("upload") || lower.Contains("photon") || lower.Contains("room"))
        {
            Debug.Log("[TurtleRecConnector] Request: " + __instance.method + " " + __instance.url);
        }
    }
}
