/* Copyright (C) 2011-2013 Zeex
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <sampgdk/bool.h>
#include <sampgdk/core.h>
#include <sampgdk/sdk.h>

#include "amx.h"
#include "init.h"
#include "log.h"
#include "logprintf.h"
#include "native.h"
#include "plugin.h"
#include "timer.h"

#ifdef _MSC_VER
  #define RETURN_ADDRESS() _ReturnAddress()
#else
  #define RETURN_ADDRESS() __builtin_return_address(0)
#endif

static sampgdk_public_hook public_hook;

SAMPGDK_EXPORT sampgdk_logprintf_t sampgdk_logprintf = NULL;
SAMPGDK_EXPORT sampgdk_vlogprintf_t sampgdk_vlogprintf = NULL;

static void init_logprintf(void **plugin_data) {
  void *logprintf = plugin_data[PLUGIN_DATA_LOGPRINTF];
  sampgdk_logprintf  = logprintf;
  sampgdk_vlogprintf = sampgdk_do_vlogprintf;
}

static void init_amx_exports(void **plugin_data) {
  sampgdk_amx_exports = plugin_data[PLUGIN_DATA_AMX_EXPORTS];
}

static int init(void **plugin_data) {
  init_logprintf(plugin_data);
  init_amx_exports(plugin_data);
  return sampgdk_module_init();
}

static void cleanup(void) {
  sampgdk_module_cleanup();
}

SAMPGDK_EXPORT int SAMPGDK_CALL sampgdk_init(void **plugin_data) {
  void *plugin = sampgdk_plugin_get_handle(RETURN_ADDRESS());
  return sampgdk_init_plugin(plugin, plugin_data);
}

SAMPGDK_EXPORT int SAMPGDK_CALL sampgdk_init_plugin(void *plugin,
                                                    void **plugin_data) {
  if (sampgdk_plugin_get_list() == NULL) {
    int error = init(plugin_data);
    if (error < 0) {
      sampgdk_log_error_code(error);
      return error;
    }
  }
  return sampgdk_plugin_register(plugin);
}

SAMPGDK_EXPORT int SAMPGDK_CALL sampgdk_cleanup(void) {
  void *plugin = sampgdk_plugin_get_handle(RETURN_ADDRESS());
  return sampgdk_cleanup_plugin(plugin);
}

SAMPGDK_EXPORT int SAMPGDK_CALL sampgdk_cleanup_plugin(void *plugin) {
  int error = sampgdk_plugin_unregister(plugin);
  if (sampgdk_plugin_get_list() == NULL) {
    cleanup();
  }
  return error;
}

SAMPGDK_EXPORT int SAMPGDK_CALL sampgdk_register_plugin(void *plugin) {
  return sampgdk_plugin_register(plugin);
}

SAMPGDK_EXPORT int SAMPGDK_CALL sampgdk_unregister_plugin(void *plugin) {
  return sampgdk_plugin_unregister(plugin);
}

SAMPGDK_EXPORT void *SAMPGDK_CALL sampgdk_get_plugin_handle(void *symbol) {
  return sampgdk_plugin_get_handle(symbol);
}

SAMPGDK_EXPORT void *SAMPGDK_CALL sampgdk_get_plugin_symbol(void *plugin,
                                                            const char *name) {
  return sampgdk_plugin_get_symbol(plugin, name);
}

SAMPGDK_EXPORT void SAMPGDK_CALL sampgdk_process_timers(void) {
  sampgdk_timer_process_timers(NULL);
}

SAMPGDK_EXPORT void SAMPGDK_CALL sampgdk_process_plugin_timers(void *plugin) {
  sampgdk_timer_process_timers(plugin);
}

SAMPGDK_EXPORT const AMX_NATIVE_INFO *SAMPGDK_CALL sampgdk_get_natives(void) {
  return sampgdk_native_get_natives();
}

SAMPGDK_EXPORT int SAMPGDK_CALL sampgdk_get_num_natives(void) {
  return sampgdk_native_get_num_natives();
}

SAMPGDK_EXPORT AMX_NATIVE SAMPGDK_CALL sampgdk_find_native(const char *name) {
  return sampgdk_native_find(name);
}

SAMPGDK_EXPORT cell SAMPGDK_CALL sampgdk_call_native(AMX_NATIVE native,
                                                     cell *params) {
  return sampgdk_native_call(native, params);
}

SAMPGDK_EXPORT cell SAMPGDK_CALL sampgdk_invoke_native(AMX_NATIVE native,
                                                      const char *format, ...) {
  va_list args;
  cell retval;

  va_start(args, format);
  retval = sampgdk_native_invoke(native, format, args);
  va_end(args);

  return retval;
}

SAMPGDK_EXPORT sampgdk_public_hook SAMPGDK_CALL sampgdk_get_public_hook(void) {
  return public_hook;
}

SAMPGDK_EXPORT void SAMPGDK_CALL sampgdk_set_public_hook(
                                                     sampgdk_public_hook hook) {
  public_hook = hook;
}
