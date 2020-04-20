/********************************************************************************************************
 * @File  : wrpnetwork.hpp
 * @Date  : 2019-10-06
 * @Author: nguyenhtm - htminhnguyen@gmail.com
 *
 ********************************************************************************************************/
#ifndef WRPBASE_WRPSYS_WRPNETWORK_HPP_
#define WRPBASE_WRPSYS_WRPNETWORK_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpbase/wrpbase.hpp"
#include "wrpsys.hpp"
#include "mongoose.h"

namespace WrpSys {
namespace Network {

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define NETWORK_STATUS_INIT          (0x00)
#define NETWORK_STATUS_NOTCONNECTED  (0x01)
#define NETWORK_STATUS_CONNECTING    (0x02)
#define NETWORK_STATUS_CONNECTED     (0x03)

enum eWrpWebSocketStatus
{
	WSCLIENT_STATUS_NOTCREATED = 0,
	WSCLIENT_STATUS_CREATED,
	WSCLIENT_STATUS_NOTCONNECTED,
	WSCLIENT_STATUS_CONNECTED
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
extern uint32_t gNetworkStatus;

void InitWifiStation();

void DeInitWifiStation();

class WrpWebSocketClient
{
public:
	WrpWebSocketClient();
	virtual ~WrpWebSocketClient();
	bool Create(const char *uri, const unsigned int port);
	void Close();
	uint32_t Receive(char* buf, int size);
	void Send(const char* buf, const uint8_t size);
	void ClearBuffer();

	static char  m_data[255];
	static unsigned int m_datalength;
	static eWrpWebSocketStatus m_status;

protected:

private:
	static void EventHandler(struct mg_connection *nc, int event, void *data);
	static struct mg_mgr *mgr;
	static struct mg_connection *nc;
	static std::string m_addr;
	uint16_t    m_port;
};

} /* Namespace Network */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPNETWORK_HPP_ */
