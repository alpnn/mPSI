#pragma once

#include "Common/Defines.h"
#include "Network/Channel.h"
#include "NChooseOne/NcoOtExt.h"
//#include "libPSI/Tools/CuckooHasher.h"
//#include "cryptoTools/Common/CuckooIndex.h"

namespace osuCrypto
{

    class KkrtPsiReceiver
    {
    public:
        KkrtPsiReceiver();
        ~KkrtPsiReceiver();

        u64 mRecverSize,mSenderSize,mStatSecParam;
        std::vector<u64> mIntersection;
        //CuckooIndex mIndex;

        NcoOtExtReceiver * mOtRecv;

        block mHashingSeed;
        
        void init(u64 senderSize, u64 recverSize, u64 statSecParam, Channel chl0, NcoOtExtReceiver& otRecv,  block seed);
        void init(u64 senderSize, u64 recverSize, u64 statSecParam, std::vector<Channel> chls, NcoOtExtReceiver& otRecv,  block seed);
        void sendInput(std::vector<block> inputs, Channel& chl);
        void sendInput(std::vector<block> inputs, std::vector<Channel> chls);

    };




}
