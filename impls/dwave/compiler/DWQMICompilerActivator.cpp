#include "DWQMICompiler.hpp"

#include "cppmicroservices/BundleActivator.h"
#include "cppmicroservices/BundleContext.h"
#include "cppmicroservices/ServiceProperties.h"

#include <memory>
#include <set>

using namespace cppmicroservices;

namespace {

/**
 * This class implements a bundle activator that uses the bundle
 * context to register an English language dictionary service
 * with the C++ Micro Services registry during static initialization
 * of the bundle. The dictionary service interface is
 * defined in a separate file and is implemented by a nested class.
 */
class US_ABI_LOCAL DWQMICompilerActivator : public BundleActivator
{


public:

	DWQMICompilerActivator() {}

  /**
   * Implements BundleActivator::Start(). Registers an
	 * instance of a dictionary service using the bundle context;
	 * attaches properties to the service that can be queried
	 * when performing a service look-up.
	 * @param context the context for the bundle.
	 */
	void Start(BundleContext context) {
		auto c = std::make_shared<
				xacc::quantum::DWQMICompiler>();
		context.RegisterService<xacc::Compiler>(
				c);
	}

	/**
	 * Implements BundleActivator::Stop(). Does nothing since
	 * the C++ Micro Services library will automatically unregister any registered services.
	 * @param context the context for the bundle.
	 */
	void Stop(BundleContext /*context*/) {
		// NOTE: The service is automatically unregistered
	}

};

}

CPPMICROSERVICES_EXPORT_BUNDLE_ACTIVATOR(DWQMICompilerActivator)
