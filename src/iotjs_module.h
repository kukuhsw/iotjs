/* Copyright 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IOTJS_MODULE_H
#define IOTJS_MODULE_H

#include "iotjs_binding.h"


namespace iotjs {

typedef JObject* (*register_func)();

enum ModuleKind {
  MODULE_BUFFER,
  MODULE_CONSOLE,
  MODULE_FS,
  MODULE_PROCESS,
  MODULE_TIMER,
  MODULE_COUNT,
};


struct Module {
  ModuleKind kind;
  JObject* module;
  register_func fn_register;
};


void InitModuleList();

void CleanupModuleList();

Module* GetBuiltinModule(ModuleKind kind);

} // namespace iotjs

#endif /* IOTJS_MODULE_H */