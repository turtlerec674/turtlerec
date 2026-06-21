using UnityEngine;

public static class TurtleRecCustomConnector
{
    public static string BackendUrl = "http://127.0.0.1:3000";

    public static void Init()
    {
        Debug.Log("[TurtleRecCustomConnector] Loaded");
        Debug.Log("[TurtleRecCustomConnector] Backend: " + BackendUrl);
    }

    public static string RedirectUrl(string oldUrl)
    {
        if (string.IsNullOrEmpty(oldUrl)) return oldUrl;

        string newUrl = oldUrl
            .Replace("https://api.rec.net", BackendUrl)
            .Replace("http://api.rec.net", BackendUrl)
            .Replace("https://accounts.rec.net", BackendUrl)
            .Replace("http://accounts.rec.net", BackendUrl)
            .Replace("https://rec.net", BackendUrl)
            .Replace("http://rec.net", BackendUrl)
            .Replace("https://images.rec.net", BackendUrl)
            .Replace("http://images.rec.net", BackendUrl)
            .Replace("https://match.rec.net", BackendUrl)
            .Replace("http://match.rec.net", BackendUrl);

        if (newUrl != oldUrl)
            Debug.Log("[TurtleRecCustomConnector] Redirected: " + oldUrl + " -> " + newUrl);

        return newUrl;
    }
}
