/*
 ----------------------------------------------------------------------------------------

 "Copyright 2014-2015 Intel Corporation.

 The source code, information and material ("Material") contained herein is owned by Intel Corporation
 or its suppliers or licensors, and title to such Material remains with Intel Corporation or its suppliers
 or licensors. The Material contains proprietary information of Intel or its suppliers and licensors. 
 The Material is protected by worldwide copyright laws and treaty provisions. No part of the Material may 
 be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed or disclosed
 in any way without Intel's prior express written permission. No license under any patent, copyright or 
 other intellectual property rights in the Material is granted to or conferred upon you, either expressly, 
 by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights 
 must be express and approved by Intel in writing.

 Unless otherwise agreed by Intel in writing, you may not remove or alter this notice or any other notice 
 embedded in Materials by Intel or Intel's suppliers or licensors in any way."
 -----------------------------------------------------------------------------------------
*/

/*
* Intel confidential -- do not distribute further
* This source code is distributed covered by "Internal License Agreement -- For Internal Open Source DaVinci Program"
* Please read and accept license.txt distributed with this package before using this source code
*/
#ifndef __RESULT_CHECKER_HPP__
#define __RESULT_CHECKER_HPP__

#include "Checker.hpp"
#include "DialogChecker.hpp"
#include "VideoChecker.hpp"
#include "AudioChecker.hpp"
#include "RunningChecker.hpp"
#include "TestReport.hpp"

namespace DaVinci
{
    using namespace std;

    class ScriptReplayer;

    /// <summary> A base class for resultchecker. </summary>
    class ResultChecker : public Checker
    {
        public:
            boost::shared_ptr<RunningChecker> Running;
            boost::shared_ptr<DialogChecker> Dialog;
            boost::shared_ptr<VideoChecker> Video;
            boost::shared_ptr<AudioChecker> Audio;
            boost::shared_ptr<Checker> Runtime;
            boost::shared_ptr<Checker> Agent;
            boost::shared_ptr<TestReportSummary> testTxtReportSummary;
            boost::shared_ptr<TestReport> testReport;
            boost::weak_ptr<ScriptReplayer> currentQScript;

            explicit ResultChecker(const boost::weak_ptr<ScriptReplayer> obj);
    
            virtual ~ResultChecker();

            /// <summary>
            /// Start all online checkers' worker thread
            /// </summary>
            void StartOnlineChecking();

            /// <summary>
            /// Stop all online checkers' worker thread
            /// </summary>
            void StopOnlineChecking();

            /// <summary>
            /// Pause all online checkers' worker thread
            /// </summary>
            void PauseOnlineChecking();

            /// <summary>
            /// Resume all online checkers' worker thread
            /// </summary>
            void ResumeOnlineChecking();

            /// <summary>
            /// Update checkpoints by opcode, say: stop all test when EXIT.
            /// </summary>
            void UpdateCheckpoints(int opcode);

            /// <summary>
            /// Start all offline checkers' worker thread
            /// </summary>
            void StartOfflineChecking();

            /// <summary>
            /// Stop all offline checkers' worker thread
            /// </summary>
            /// void StopOfflineChecking();

            /// <summary>
            /// Result checking report.
            /// </summary>
            void FinalReport();

    };
}

#endif