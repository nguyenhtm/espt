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

enum eWrpWebSocketStatus
{
	WSCLIENT_STATUS_INIT = 0,
	WSCLIENT_STATUS_CREATED,
	WSCLIENT_STATUS_CONNECTED,
	WSCLIENT_STATUS_CONNECTED_ERROR,
	WSCLIENT_STATUS_POLLED,
	WSCLIENT_STATUS_DATA_RECEIVED,
	WSCLIENT_STATUS_CLOSED
};

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/

void InitWifiStation();

class WrpWebSocketClient
{
public:
	WrpWebSocketClient();
	virtual ~WrpWebSocketClient();
	bool Create(const char *uri, const unsigned int port);
	void Close();
	int Receive(char* buf, int size);
	void ClearBuffer();

	static char  m_data[255];
	static unsigned int m_datalength;
	static eWrpWebSocketStatus m_status;

protected:

private:
	static void EventHandler(struct mg_connection *nc, int event, void *data);
	static struct mg_mgr mgr;
	static struct mg_connection *nc;
};

} /* Namespace WrpSysNetwork */
} /* Namespace WrpSys */

#endif /* WRPBASE_WRPSYS_WRPNETWORK_HPP_ */
