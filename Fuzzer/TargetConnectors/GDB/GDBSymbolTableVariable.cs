// GDBSymbolTableVariable.cs
//  
//  Author:
//       Andreas Reiter <andreas.reiter@student.tugraz.at>
// 
//  Copyright 2011  Andreas Reiter
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
using System;
using System.Threading;
namespace Fuzzer.TargetConnectors.GDB
{
	/// <summary>
	/// Represents a variable that gets resolved at runtime
	/// </summary>
	public class GDBSymbolTableVariable : ISymbolTableVariable
	{
		private GDBConnector _connector;
		private string _name;
		
		public GDBSymbolTableVariable (GDBConnector connector, string name)
		{
			_connector = connector;
			_name = name;
		}
	

		#region ISymbolTableVariable implementation
		public string Name 
		{
			get { return _name; }
		}

		public string Symbol
		{
			get { return Name; }
		}
		
		public UInt64? Address 
		{
			get 
			{
				//Resolve the address
				IAddressSpecifier myAddress = null;
				ManualResetEvent evt = new ManualResetEvent (false);
				
				//Step 1: "info address <name>" to get the location of the value
				_connector.QueueCommand (new InfoAddressCmd (this, 
				delegate(ISymbol symbol, IAddressSpecifier address)
				{
					myAddress = address;
					evt.Set ();
				}, _connector));
				
				evt.WaitOne ();
				
				if (myAddress == null)
					return null;
				
				return myAddress.ResolveAddress ();
			}
		}
		#endregion
}
}
