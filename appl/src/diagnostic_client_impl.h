/* MANDAREIN Diagnostic Client library
 * Copyright (C) 2022  Avijit Dey
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _DIAGNOSTIC_CLIENT_IMPL_H_
#define _DIAGNOSTIC_CLIENT_IMPL_H_

#include "diagnostic_client.h"
#include "diagnostic_client_conversion.h"
#include "common_Header.h"
#include "libJsonParser/jsonParser.h"
#include "dcm/diagnostic_communication_manager.h"
#include "common/diagnostic_manager.h"

namespace diag {
namespace client {

class DiagClientImpl : public diag::client::DiagClient {

public:
    // ctor
    DiagClientImpl(std::string dm_client_config);

    // dtor
    ~DiagClientImpl();

    // Initialize
    void Initialize() override;

    // De-Initialize
    void DeInitialize() override;

    // Get Required Conversion based on Conversion Name
    diag::client::conversion::DiagClientConversion& 
                    GetDiagnosticClientConversion(std::string conversion_name) override;

private:
    // Used to read json 
    diag::client::common::property_tree ptree;

    // dcm client instance
    std::unique_ptr<diag::client::dcm::DCMClient> dcm_instance_ptr;
    
    // container to hold threads
    std::vector<std::thread> _thread;
    
    // Declare dlt logging context
    DLT_DECLARE_CONTEXT(diagclient_main);
};



} // client
} // diag

#endif // _DIAGNOSTIC_CLIENT_IMPL_H_