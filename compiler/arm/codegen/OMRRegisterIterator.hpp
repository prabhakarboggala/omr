/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2016
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#ifndef OMR_ARM_REGISTER_ITERATOR_INCL
#define OMR_ARM_REGISTER_ITERATOR_INCL

/*
 * The following #define and typedef must appear before any #includes in this file
 */
#ifndef OMR_REGISTER_ITERATOR_CONNECTOR
#define OMR_REGISTER_ITERATOR_CONNECTOR
   namespace OMR { namespace ARM { class RegisterIterator; } }
   namespace OMR { typedef OMR::ARM::RegisterIterator RegisterIteratorConnector; }
#else
   #error OMR::ARM::RegisterIterator expected to be a primary connector, but a OMR connector is already defined
#endif

#include "compiler/codegen/OMRRegisterIterator.hpp"
namespace TR { class Machine; }

namespace OMR
{

namespace ARM
{

class OMR_EXTENSIBLE RegisterIterator : public OMR::RegisterIterator
   {
   public:
   RegisterIterator(TR::Machine *machine, TR_RegisterKinds kind);

   TR::Register *getFirst();
   TR::Register *getCurrent();
   TR::Register *getNext();

   private:
   TR::Machine *_machine;
   int32_t _firstRegIndex;
   int32_t _lastRegIndex;
   int32_t _cursor;
   };

}

}


#endif
