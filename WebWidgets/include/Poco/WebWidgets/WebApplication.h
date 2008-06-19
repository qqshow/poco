//
// WebApplication.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/WebApplication.h#6 $
//
// Library: WebWidgets
// Package: Core
// Module:  WebApplication
//
// Definition of the WebApplication class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
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


#ifndef WebWidgets_WebApplication_INCLUDED
#define WebWidgets_WebApplication_INCLUDED


#include "Poco/WebWidgets/WebWidgets.h"
#include "Poco/WebWidgets/Page.h"
#include "Poco/WebWidgets/LookAndFeel.h"
#include "Poco/WebWidgets/ResourceManager.h"
#include "Poco/ThreadLocal.h"
#include "Poco/URI.h"
#include <map>


namespace Poco {
	namespace Net {
		class HTMLForm;
	}
namespace WebWidgets {


class RequestProcessor;


class WebWidgets_API WebApplication
	/// WebApplication class
{
public:
	WebApplication(const Poco::URI& uri, ResourceManager::Ptr pRM);
		/// Creates the WebApplication.

	virtual ~WebApplication();
		/// Destroys the WebApplication.

	void setLookAndFeel(LookAndFeel::Ptr pLookAndFeel);
		/// Sets the application's LookAndFeel.

	LookAndFeel::Ptr getLookAndFeel() const;
		/// Returns the application's LookAndFeel.

	void setCurrentPage(Page::Ptr pPage);
		/// Sets the currently active page.

	Page::Ptr getCurrentPage() const;
		/// Returns the currently active page.
		
	void setResourceManager(ResourceManager::Ptr pRM);
		/// Sets the ResourceManager
		
	ResourceManager::Ptr getResourceManager() const;
		/// Gets the ResourceManager

	void registerFormProcessor(const std::string& fieldName, RequestProcessor* pProc);
		/// Registers a RequestProcessor for a given form field.

	void handleForm(const Poco::Net::HTMLForm& form);
		///Handles a form

	RequestProcessor* getFormProcessor(const std::string& fieldName);
		/// Returns the requestprocessor or null
		
	void registerAjaxProcessor(const std::string& id, RequestProcessor* pProc);
		/// Registers a RequestProcessor for a request.
		
	RequestProcessor* getAjaxProcessor(const std::string& id);
		/// Returns the AjaxProcessor or null

	void attachToThread();
		/// Attaches the WebApplication to the current thread, so that a
		/// call to WebApplication::instance() within this thread will return 
		/// exactly this WebApplication instance.

	const Poco::URI& getURI() const;
		/// Returns the home location of the application

	static WebApplication& instance();
		/// Returns the singleton for the current thread
private:
	WebApplication(const WebApplication&);
	WebApplication& operator = (const WebApplication&);
	
	typedef std::map<std::string, RequestProcessor* > RequestProcessorMap;
	
	ResourceManager::Ptr _pResource;
	LookAndFeel::Ptr _pLookAndFeel;
	Page::Ptr _pCurrentPage;
	Poco::URI _uri;
	RequestProcessorMap _requestProcessorMap;
	RequestProcessorMap _ajaxProcessorMap;
	static Poco::ThreadLocal<WebApplication*> _pInstance;
};


//
// inlines
//
inline LookAndFeel::Ptr WebApplication::getLookAndFeel() const
{
	return _pLookAndFeel;
}


inline Page::Ptr WebApplication::getCurrentPage() const
{
	return _pCurrentPage;
}


inline const Poco::URI& WebApplication::getURI() const
{
	return _uri;
}


inline void WebApplication::setResourceManager(ResourceManager::Ptr pRM)
{
	poco_check_ptr (pRM);
	_pResource = pRM;
}

		
inline ResourceManager::Ptr WebApplication::getResourceManager() const
{
	return _pResource;
}
		

} } // namespace Poco::WebWidgets


#endif // WebWidgets_WebApplication_INCLUDED