//
// PooledSessionImpl.h
//
// $Id: //poco/Main/Data/include/Poco/Data/PooledSessionImpl.h#2 $
//
// Library: Data
// Package: SessionPooling
// Module:  PooledSessionImpl
//
// Definition of the PooledSessionImpl class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Data_PooledSessionImpl_INCLUDED
#define Data_PooledSessionImpl_INCLUDED


#include "Poco/Data/Data.h"
#include "Poco/Data/SessionImpl.h"
#include "Poco/Data/PooledSessionHolder.h"
#include "Poco/AutoPtr.h"


namespace Poco {
namespace Data {


class SessionPool;


class Data_API PooledSessionImpl: public SessionImpl
	/// PooledSessionImpl is a decorator created by
	/// SessionPool that adds session pool
	/// management to SessionImpl objects.
{
public:
	PooledSessionImpl(PooledSessionHolder* pHolder);
		/// Creates the PooledSessionImpl.

	~PooledSessionImpl();
		/// Destroys the PooledSessionImpl.

	// SessionImpl
	StatementImpl* createStatementImpl();
	void begin();
	void commit();
	void rollback();
	void close();
	bool isConnected();
	void setFeature(const std::string& name, bool state);	
	bool getFeature(const std::string& name);
	void setProperty(const std::string& name, const Poco::Any& value);
	Poco::Any getProperty(const std::string& name);
	
protected:
	SessionImpl* access();
		/// Updates the last access timestamp,
		/// verifies validity of the session
		/// and returns the session if it is valid.
		///
		/// Throws an SessionUnavailableException if the
		/// session is no longer valid.
		
	SessionImpl* impl();
		/// Returns a pointer to the SessionImpl.
				
private:	
	Poco::AutoPtr<PooledSessionHolder> _pHolder;
};


//
// inlines
//
inline SessionImpl* PooledSessionImpl::impl()
{
	return _pHolder->session();
}


} } // namespace Poco::Data


#endif // Data_PooledSessionImpl_INCLUDED