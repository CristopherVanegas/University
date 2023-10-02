import { Fragment, useState, useEffect } from 'react'
import { useOutletContext } from '@remix-run/react'
import { Dialog, Transition } from '@headlessui/react'

export default function Disponibilidad({mensaje, disponibilidad, setDisponibilidad}) {

    const closeModal = () => {
        setDisponibilidad({disponibilidad: true, mensaje: ''});
    }

    return (
        <>
            <Transition appear show={!disponibilidad} as={Fragment}>
                <Dialog as="div" className="relative z-50" onClose={closeModal}>
                    <Transition.Child
                        as={Fragment}
                        enter="ease-out duration-300"
                        enterFrom="opacity-0"
                        enterTo="opacity-100"
                        leave="ease-in duration-200"
                        leaveFrom="opacity-100"
                        leaveTo="opacity-0"
                    >
                        <div className="fixed inset-0 bg-black bg-opacity-60" />
                    </Transition.Child>

                    <div className="fixed inset-0 overflow-y-auto">
                        <div className="flex min-h-full items-center justify-center p-4 text-center">
                            <Transition.Child
                                as={Fragment}
                                enter="ease-out duration-300"
                                enterFrom="opacity-0 scale-95"
                                enterTo="opacity-100 scale-100"
                                leave="ease-in duration-200"
                                leaveFrom="opacity-100 scale-100"
                                leaveTo="opacity-0 scale-95"
                            >
                                <Dialog.Panel className="w-full max-w-md transform overflow-hidden rounded-2xl bg-white p-6 text-left align-middle shadow-xl transition-all flex flex-col justify-center items-center">
                                    <Dialog.Title
                                        as="h3"
                                        className={`text-lg font-bold leading-6 text-gray-900`}
                                    >
                                        {`Apertura: ${new Date().getHours() >= 0 && new Date().getHours() <= 6 ? "Hoy" : "Mañana"}, 7:00 AM`}
                                    </Dialog.Title>

                                    <div className="mt-2">
                                        <p className="text-sm text-gray-500 text-center">
                                            {mensaje}
                                        </p>
                                    </div>

                                    <div className="mt-4">
                                        <button
                                            type="button"
                                            className="text-white capitalize bg-color-aloha rounded-lg sombra-aloha-roja px-3 py-2 m-auto font-semibold border-none outline-none"
                                            onClick={closeModal}
                                        >
                                            Entendido, ver productos!
                                        </button>
                                    </div>
                                </Dialog.Panel>
                            </Transition.Child>
                        </div>
                    </div>
                </Dialog>
            </Transition>
        </>
    )
}
