/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 or later licence
 *
 * $Id: RelParsIfaceOpt.cpp,v 1.1 2005-01-11 22:53:35 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 */

#include "RelParsIfaceOpt.h"

TRelParsIfaceOpt::TRelParsIfaceOpt(void) {
    this->ServerUnicast = 0; // NULL
    this->ClientUnicast = 0;
    this->ServerMulticast = false;
    this->ClientMulticast = false;
    this->InterfaceID = -1;
}

TRelParsIfaceOpt::~TRelParsIfaceOpt(void) {
}

// --- unicast ---
void TRelParsIfaceOpt::setServerUnicast(SmartPtr<TIPv6Addr> addr) {
    this->ServerUnicast = addr;
}

SmartPtr<TIPv6Addr> TRelParsIfaceOpt::getServerUnicast() {
    return this->ServerUnicast;
}

void TRelParsIfaceOpt::setClientUnicast(SmartPtr<TIPv6Addr> addr) {
    this->ClientUnicast = addr;
}

SmartPtr<TIPv6Addr> TRelParsIfaceOpt::getClientUnicast() {
    return this->ClientUnicast;
}


void TRelParsIfaceOpt::setClientMulticast(bool multi) {
    this->ClientMulticast = multi;
}

bool TRelParsIfaceOpt::getClientMulticast() {
    return this->ClientMulticast;
}

void TRelParsIfaceOpt::setServerMulticast(bool multi) {
    this->ServerMulticast = multi;
}

bool TRelParsIfaceOpt::getServerMulticast() {
    return this->ServerMulticast;
}

void TRelParsIfaceOpt::setInterfaceID(int id) {
    this->InterfaceID= id;
}

int TRelParsIfaceOpt::getInterfaceID() {
    return this->InterfaceID;
}