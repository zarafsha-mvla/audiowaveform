//
//  Network.cpp
//  audiowaveform
//
//  Created by Aubteen Zarafshar on 11/13/22.
//
#include "Network.hpp"

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

bool GetFile(const char *url, const char *name)
{
    return GetFile(url, name);
}

bool checkUrl(std::string url)
{
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (CURLE_OK == res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool GetFile(std::string url)
{
    // Get the name from the url by taking the end
    std::string name = url.substr(url.find_last_of("/") + 1);
    return GetFile(url, name);
}

bool GetFile(std::string url, std::string name)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (!checkUrl(url))
    {
        return false;
    }
    if (curl)
    {
        fp = fopen(name.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        std::cout << "Downloading " << name << " from " << url << std::endl;
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    curl_global_cleanup();
    return true;
}
