/******************************************************************
 *
 * Copyright 2015 Samsung Electronics All Rights Reserved.
 *
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/

#ifndef __JNIOCSECURITY_H
#define __JNIOCSECURITY_H

#include <stdint.h>
#include <stdio.h>
#include <string>
#include "octypes.h"
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

namespace OC
{
    class JniOcSecurity
    {
        private:
            static FILE* client_open(const char*, const char*);
        public:
            static std::string& store_path(void);
            static std::string& store_introspection();
            static void StoreDbPath(const std::string&);
            static void StoreIntrospection(const std::string&);
            static OCPersistentStorage* getOCPersistentStorage(void);
    };
}
#endif //__JNIOCSECURITY_H
