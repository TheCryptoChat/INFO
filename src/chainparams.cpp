// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//
// Main network
//

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x9f;
        pchMessageStart[1] = 0xaa;
        pchMessageStart[2] = 0x37;
        pchMessageStart[3] = 0x7a;
        nDefaultPort = 42856;
        nRPCPort = 42857;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 18);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        /*
        Hashed MainNet Genesis Block Output
        block.hashMerkleRoot == d8faa98d79f851f3a41b738c06c9475bcceae7a390c3a863031df609619fa693
        block.nTime = 1497873600
        block.nNonce = 89352
        block.GetHash = 00002ad12fbaac37e7d4abcfd4e47fb3868b58e9c2de4e0b9152a5f3e0173b0b
        */

        const char* pszTimestamp = "A Severed Undersea Internet Cable Can Bring Bitcoin to its Knees - JP Buntinx - June 19, 2017"; // Monday, June 19, 2017 12:00:00 PM
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1497873600, vin, vout, 0); // Monday, June 19, 2017 12:00:00 PM
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1497873600; // Monday, June 19, 2017 12:00:00 PM
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 89352;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00002ad12fbaac37e7d4abcfd4e47fb3868b58e9c2de4e0b9152a5f3e0173b0b"));
        assert(genesis.hashMerkleRoot == uint256("0xd8faa98d79f851f3a41b738c06c9475bcceae7a390c3a863031df609619fa693"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,102);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,67);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,64);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x50)(0xE7)(0xFC)(0x0A).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x50)(0x9E)(0x4)(0x2F).convert_to_container<std::vector<unsigned char> >();

        // Infocoin dns seeds
        //vSeeds.push_back(CDNSSeedData("Seed",  "0.0.0.0"));

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 0x7fffffff;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x81;
        pchMessageStart[1] = 0xfe;
        pchMessageStart[2] = 0xa2;
        pchMessageStart[3] = 0xee;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        nDefaultPort = 42859;
        nRPCPort = 42858;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nTime    = 1497873800; // Monday, June 19, 2017 12:00:00 PM
        genesis.nNonce = 33634;

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        /*
        Hashed TestNet Genesis Block Output
        block.hashMerkleRoot == d8faa98d79f851f3a41b738c06c9475bcceae7a390c3a863031df609619fa693
        block.nTime = 1497873800
        block.nNonce = 33634
        block.GetHash = 000018cd4d1285a5d84ac1168e5baccb0820ac9e4b5d76824d986c8b64c9eadb
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000018cd4d1285a5d84ac1168e5baccb0820ac9e4b5d76824d986c8b64c9eadb"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,102);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,19);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,23);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x1D)(0x9B)(0x7F)(0x74).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x1D)(0xC0)(0xFC)(0x28).convert_to_container<std::vector<unsigned char> >();

        // Infocoin dns seeds
        // vSeeds.push_back(CDNSSeedData("Seed",  "0.0.0.0"));

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x22;
        pchMessageStart[1] = 0xfe;
        pchMessageStart[2] = 0x98;
        pchMessageStart[3] = 0xca;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1497873300; // Monday, June 19, 2017 12:00:00 PM
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 9;
        nDefaultPort = 11003;
        strDataDir = "regtest";

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        /*
        Hashed RegNet Genesis Block Output
        block.hashMerkleRoot == d8faa98d79f851f3a41b738c06c9475bcceae7a390c3a863031df609619fa693
        block.nTime = 1497873300
        block.nNonce = 9
        block.GetHash = 51da2d522e0baafbbd61dfeb176dc50cc52db06c8178ae0d57e1202455a500fe
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x51da2d522e0baafbbd61dfeb176dc50cc52db06c8178ae0d57e1202455a500fe"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
