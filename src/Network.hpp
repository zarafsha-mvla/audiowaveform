//
//  Network.hpp
//  audiowaveform
//
//  Created by Aubteen Zarafshar on 11/13/22.
//

#ifndef Network_hpp
#define Network_hpp

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <curl/curl.h>
#include <iostream>

bool GetFile(const char *url, const char *name);
bool GetFile(std::string url, std::string name);
bool GetFile(std::string url);

#endif /* Network_hpp */
