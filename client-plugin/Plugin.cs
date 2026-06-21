using BepInEx;
using HarmonyLib;
using UnityEngine;
using UnityEngine.Networking;

namespace TurtleRecConnector
{
    [BepInPlugin("com.turtlerec.connector", "TurtleRec Connector", "1.0.0")]
    public class Plugin : BaseUnityPlugin
    {
        public static string BackendUrl = "http://127.0.0.1:3000";

        private void Awake()
        {
            Logger.LogInfo("TurtleRec Connector loaded.");
            Logger.LogInfo("Redirecting RecNet/API traffic to: " + BackendUrl);

            Harmony harmony = new Harmony("com.turtlerec.connector");
            harmony.PatchAll();
        }
    }

    [HarmonyPatch(typeof(UnityWebRequest))]
    public static class UnityWebRequestPatch
    {
        [HarmonyPatch("set_url")]
        [HarmonyPrefix]
        public static void PatchUrl(ref string value)
        {
            if (string.IsNullOrEmpty(value))
                return;

            string oldUrl = value;

            value = value
                .Replace("https://accounts.rec.net", Plugin.BackendUrl)
                .Replace("https://api.rec.net", Plugin.BackendUrl)
                .Replace("https://match.rec.net", Plugin.BackendUrl)
                .Replace("https://rooms.rec.net", Plugin.BackendUrl)
                .Replace("https://images.rec.net", Plugin.BackendUrl)
                .Replace("https://cdn.rec.net", Plugin.BackendUrl)
                .Replace("https://rec.net", Plugin.BackendUrl)
                .Replace("http://accounts.rec.net", Plugin.BackendUrl)
                .Replace("http://api.rec.net", Plugin.BackendUrl)
                .Replace("http://match.rec.net", Plugin.BackendUrl)
                .Replace("http://rooms.rec.net", Plugin.BackendUrl)
                .Replace("http://images.rec.net", Plugin.BackendUrl)
                .Replace("http://cdn.rec.net", Plugin.BackendUrl)
                .Replace("http://rec.net", Plugin.BackendUrl);

            if (oldUrl != value)
            {
                Debug.Log("[TurtleRecConnector] Redirected: " + oldUrl + " -> " + value);
            }
        }
    }
}
