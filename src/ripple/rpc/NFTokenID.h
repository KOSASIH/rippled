//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2023 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef RIPPLE_RPC_NFTOKENID_H_INCLUDED
#define RIPPLE_RPC_NFTOKENID_H_INCLUDED

#include <ripple/protocol/Protocol.h>

#include <functional>
#include <memory>

namespace Json {
class Value;
}

namespace ripple {

class TxMeta;
class STTx;

namespace RPC {

/**
   Add a `nftoken_ids` field to the `meta` output parameter.
   The field is only added to successful NFTokenMint, NFTokenAcceptOffer,
   and NFTokenCancelOffer transactions.

   Helper functions are not static because they can be used by Clio.
   @{
 */
bool
canHaveNFTokenID(
    std::shared_ptr<STTx const> const& serializedTx,
    TxMeta const& transactionMeta);

std::optional<uint256>
getNFTokenIDFromPage(TxMeta const& transactionMeta);

std::vector<uint256>
getNFTokenIDFromDeletedOffer(TxMeta const& transactionMeta);

void
insertNFTokenID(
    Json::Value& response,
    std::shared_ptr<STTx const> const& transaction,
    TxMeta const& transactionMeta);
/** @} */

}  // namespace RPC
}  // namespace ripple

#endif
