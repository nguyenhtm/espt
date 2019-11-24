/********************************************************************************************************
 * @File  : wrpsys.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPSYS_WRPSYS_HPP_
#define WRPSYS_WRPSYS_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#if USE_ESP_IDF

// websocket data types
typedef esp_websocket_client_handle_t wrp_wssclient_handle_t;
typedef esp_websocket_client_config_t wrp_wssclient_config_t;
typedef esp_websocket_event_data_t    wrp_wssevent_t;
// websocket event types
#define WRP_WSSEVENT_CONNECTED        WEBSOCKET_EVENT_CONNECTED
#define WRP_WSSEVENT_DISCONNECTED     WEBSOCKET_EVENT_DISCONNECTED
#define WRP_WSSEVENT_DATA             WEBSOCKET_EVENT_DATA
#define WRP_WSSEVENT_ERROR            WEBSOCKET_EVENT_ERROR

typedef void (*wss_handler_t)(void *args, esp_event_base_t base, int32_t event_id, void *event_data);
// websocket functions
#define wrp_wssclient_open(x)         esp_websocket_client_init(x)

#else

typedef int32_t                       wrp_wssclient_handle_t;
typedef int32_t                       wrp_wssclient_config_t;
typedef struct{char* data_ptr; int data_len;}                       wrp_wssevent_t;

#define WRP_WSSEVENT_CONNECTED        1
#define WRP_WSSEVENT_DISCONNECTED     2
#define WRP_WSSEVENT_DATA             3
#define WRP_WSSEVENT_ERROR            4

#define wrp_wssclient_open(x)
typedef void (*wss_handler_t)(int32_t event_id, void *event_data);

#endif


/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

#endif /* WRPSYS_WRPSYS_HPP_ */
