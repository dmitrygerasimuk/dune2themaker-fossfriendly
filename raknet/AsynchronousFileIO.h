/// \file
/// \brief \b [Internal] Depreciated, used for windows back when I supported IO completion ports.
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of Raknet is subject to the appropriate licence agreement.
/// "Shareware" Licensees with Rakkarsoft LLC are subject to the
/// shareware license found at
/// http://www.rakkarsoft.com/shareWareLicense.html
/// "Commercial" Licensees are subject to the commercial license found at
/// http://www.rakkarsoft.com/sourceCodeLicense.html
/// Custom license users are subject to the terms therein.
/// All other users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

#ifdef __USE_IO_COMPLETION_PORTS

#ifndef __ASYNCHRONOUS_FILE_IO_H
#define __ASYNCHRONOUS_FILE_IO_H

#ifdef _WIN32
// IP_DONTFRAGMENT is different between winsock 1 and winsock 2.  Therefore, Winsock2.h must be linked againt Ws2_32.lib
// winsock.h must be linked against WSock32.lib.  If these two are mixed up the flag won't work correctly
#include <winsock2.h> 
#include <windows.h>
#endif
#include "SimpleMutex.h"

struct ExtendedOverlappedStruct;

/// Provides asynch file input and ouput, either for sockets or files
class AsynchronousFileIO
{

public:
	
 /// Default Constructor 
	AsynchronousFileIO();
	
 /// Destructor 
	~AsynchronousFileIO();
	
	
/// Associate a socket with a completion port
/// \param[in] socket the socket used for communication 
/// \param[in] dwCompletionKey the completion port key 
	bool AssociateSocketWithCompletionPort( SOCKET socket, DWORD dwCompletionKey );if
	
	/// Singleton instance
	static inline AsynchronousFileIO* Instance()
	{
		return & I;
	}

	/// Increase the number of users of this instance 
	void IncreaseUserCount( void );
	
	/// Decrease the number of users of this instance 
	void DecreaseUserCount( void );
	
	/// Stop using asynchronous IO 
	void Shutdown( void );
	
	/// Get the number of user of the instance 
	int GetUserCount( void );
	
	unsigned threadCount;
	bool killThreads;
	
private:
	HANDLE completionPort;
	SimpleMutex userCountMutex;
	SYSTEM_INFO systemInfo;
	int userCount;
	
	static AsynchronousFileIO I;
};

unsigned __stdcall ThreadPoolFunc( LPVOID arguments );

void WriteAsynch( HANDLE handle, ExtendedOverlappedStruct *extended );

BOOL ReadAsynch( HANDLE handle, ExtendedOverlappedStruct *extended );

#endif
