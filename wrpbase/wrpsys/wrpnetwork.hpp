/*
 * File  : wrpnetwork.hpp
 * Date  : 2019-10-06
 * Author: AOG1HC
 *
 */

#ifndef WRPBASE_WRPSYS_WRPNETWORK_HPP_
#define WRPBASE_WRPSYS_WRPNETWORK_HPP_

/********************************************************************************************************
 * INCLUDES
 ********************************************************************************************************/
#include "wrpsys.hpp"
#include "mongoose.h"

/********************************************************************************************************
 * DEFINES
 ********************************************************************************************************/
#define WRPESP_WIFI_SSID           "Sankalp004_2"
#define WRPESP_WIFI_PASS           "9845447464"

//#define WRPESP_WIFI_SSID           "iPhone"
//#define WRPESP_WIFI_PASS           "123321123"

/********************************************************************************************************
 * CLASSES
 ********************************************************************************************************/
namespace WrpSys {
namespace WrpSysNetwork {

	void InitWifiStation();

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

	class WrpWebSocketClient
	{
	public:
		WrpWebSocketClient();
		virtual ~WrpWebSocketClient();
		bool Create(const char *uri, const unsigned int port);
		void Poll();
		void Close();
		int Receive(char* buf, int size);
		void ClearBuffer();

		static char m_data[255];
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
